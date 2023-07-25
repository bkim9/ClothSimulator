#include "Particle.h"

void Particle::Integrate(float deltaTime) {
    if(!fixed) { 
        glm::vec3 accel = (1 / Mass) * Force;
        Velocity += accel * deltaTime;
        Position += Velocity * deltaTime;
    }
    Force = glm::vec3(0);
}

glm::vec3 Particle::RandomVector() {
    srand((unsigned)NULL);
    float s = (float) rand()/RAND_MAX;
    float t = (float) rand()/RAND_MAX;
    glm::vec3 randomV(0);
    float pi = 3.141592f;
    float u = 2 * pi * s;
    float v = glm::sqrt(t * (1 - t));
    randomV.x = 2 * v * glm::cos(u);
    randomV.y = 1 - 2 * t;
    randomV.z = 2 * v * glm::sin(u);
    return randomV;
}


