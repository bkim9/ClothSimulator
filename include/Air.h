#include "core.h"
class Air {
    public:
        float density;
        float dragcoef;
        glm::vec3 wind;
        Air(float d, float c, glm::vec3 wind) {density = d; dragcoef = c; wind = wind;}
};