#pragma once
#include "core.h"
#include <time.h>

class Particle {
    public:
        void ApplyForce(glm::vec3 & f) {Force += f;}
        void Integrate(float deltaTime);
        glm::vec3 RandomVector();
        glm::vec3 Position;
        glm::vec3 Normal;
        bool fixed;
        float Mass;
        glm::vec3 Velocity;
        glm::vec3 Force;
        int degree;
};
