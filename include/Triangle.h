
#include "Particle.h"
#include "Air.h"
class Triangle {
    private:
        GLuint VAO;
        GLuint VBO_positions, VBO_normals, EBO;

        // triangle Information
        std::vector<glm::vec3> positions;
        std::vector<glm::vec3> normals;
        std::vector<unsigned int> indices;
        glm::mat4 model;
        glm::vec3 color;
    public:
        Triangle(Particle* particle0, Particle* particle1, Particle* particle2);
        ~Triangle();
        std::vector<Particle*> parts;
        glm::vec3 normal;
        float area;
        void predraw();
        void getN();
        void draw(const glm::mat4& viewProjMtx, GLuint shader);
        void Aero(Air* air);
};
