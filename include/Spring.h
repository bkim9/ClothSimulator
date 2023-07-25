#include "Particle.h"

//  <--relaxedLength-->  
// p0 -- stiffness -- p1
class Spring {

    // relaxedLength
    float relaxedLength;

    // stiffness
    float stiffness;

    // dampness
    float dampness;

    Particle* p0;
    Particle* p1;

    public:
        Spring(Particle* particle0, Particle* particle1, float k, float d, float l);
        void Applyforce();
};
