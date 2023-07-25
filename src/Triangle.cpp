#include "Triangle.h"

Triangle::Triangle(Particle* particle0, Particle* particle1, Particle* particle2) {
    parts.push_back(particle0);
    parts.push_back(particle1);
    parts.push_back(particle2);
    normal = glm::normalize(glm::cross(parts[0]->Position - parts[1]->Position, parts[0]->Position - parts[2]->Position));
    model = glm::mat4(1.0f);
}

void Triangle::predraw(){
    positions.push_back(parts[0]->Position);
    positions.push_back(parts[1]->Position);
    positions.push_back(parts[2]->Position);

    normals.push_back(parts[0]->Normal);
    normals.push_back(parts[1]->Normal);
    normals.push_back(parts[2]->Normal);

    indices = {0,1,2};

    // The color of the triangle
    color = glm::vec3(.2f, 0.5f, 0.5f);

    // Generate a vertex array (VAO) and two vertex buffer objects (VBO).
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO_positions);
    glGenBuffers(1, &VBO_normals);

    // Bind to the VAO.
    glBindVertexArray(VAO);

    // Bind to the first VBO - We will use it to store the vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_positions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    // Bind to the second VBO - We will use it to store the normals
    glBindBuffer(GL_ARRAY_BUFFER, VBO_normals);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), normals.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    // Generate EBO, bind the EBO to the bound VAO and send the data
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    // Unbind the VBOs.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Triangle::~Triangle() {
    // Delete the VBOs and the VAO.
    glDeleteBuffers(1, &VBO_positions);
    glDeleteBuffers(1, &VBO_normals);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void Triangle::draw(const glm::mat4& viewProjMtx, GLuint shader) {
    normal = glm::normalize(glm::cross(parts[0]->Position - parts[1]->Position, parts[0]->Position - parts[2]->Position));
    positions[0] = parts[0]->Position;
    positions[1] = parts[1]->Position;
    positions[2] = parts[2]->Position;

    normals[0] = parts[0]->Normal;
    normals[1] = parts[1]->Normal;
    normals[2] = parts[2]->Normal;

    // actiavte the shader program
    glUseProgram(shader);

    // update is prior to draw 

    // Bind to the first VBO - We will use it to store the vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_positions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * positions.size(), positions.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    // Bind to the second VBO - We will use it to store the normals
    glBindBuffer(GL_ARRAY_BUFFER, VBO_normals);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), normals.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    glUniformMatrix4fv(glGetUniformLocation(shader, "viewProj"), 1, false, (float*)&(viewProjMtx));
    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, (float*)&model);
    glUniform3fv(glGetUniformLocation(shader, "DiffuseColor"), 1, &color[0]);

    // Bind the VAO
    glBindVertexArray(VAO);

    // draw the points using triangles, indexed with the EBO
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    // Unbind the VAO and shader program
    glBindVertexArray(0);
    glUseProgram(0);
}

void Triangle::Aero(Air *air) {
    glm::vec3 v = (parts[0]->Velocity + parts[1]->Velocity + parts[2]->Velocity)/3.0f - air->wind;
    if (glm::length(v) < 0.001f) return;
    normal = glm::cross(parts[1]->Position - parts[0]->Position, parts[2]->Position - parts[0]->Position);
    float triArea = .5f * glm::length(normal);
    normal = glm::normalize(normal);
    float crossArea = triArea * glm::dot(glm::normalize(v),normal);
    glm::vec3 fAero = 1/3.0f * -.5f * air->density * glm::length(v) * glm::length(v) * air->dragcoef * crossArea * normal;
    for( int i = 0; i < 3; i++ ) {
        glm::vec3 fAero0 = fAero / ((float)parts[i]->degree);
        parts[i]->ApplyForce(fAero0);
    }
}
