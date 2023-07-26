#include "Spring.h"

Spring::Spring(Particle* particle0, Particle* particle1, float k, float d, float l){
    p0 = particle0;
    p1 = particle1;
    stiffness = k;
    dampness = d;
    relaxedLength = l;
}

void Spring::Applyforce() {
    // Compute current length l & unit vector e
    glm::vec3 relPos = p1->Position - p0->Position;
    float length = glm::length   (relPos);
    glm::vec3 e =  glm::normalize(relPos);
    
    //    e
    // p0 ->  p1
    //    ->
    // speedClose
    
    // closing speed 
    // + further 
    // - closer
    float speedClose = glm::dot(p1->Velocity - p0->Velocity,e);
    
    // Compute final forces
    float forceMag = .5f * (stiffness *(length - relaxedLength)+ dampness * speedClose);
    glm::vec3 f0 = forceMag * e;
    glm::vec3 f1 = -1.0f * f0;
    p0->ApplyForce( f0 );
    p1->ApplyForce( f1 );
}