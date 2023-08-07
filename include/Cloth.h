
#include "Spring.h"
#include "Floor.h"
#include <map>
class Cloth {
    private:
    int height;
    int width;
    float particledistance;
    glm::vec3 location;
    
    
    public: 

    // height: h     width: w
    //  -   0   1   2   3   w
    //  0   o   o   o   o   o
    //  1   o   o   o   o   o     
    //  h   o   o   o   o   o
    std::vector<std::vector<Particle*> > verticies;

    //      p0
    //     /  \
    //   p1 -  p2   == trianglemap[p0][p1][p2] 
    //              == trianglemap[p0][p2][p1] 
    //              == trianglemap[p1][p0][p2] 
    //              == trianglemap[p1][p2][p0] 
    //              == trianglemap[p2][p0][p1] 
    //              == trianglemap[p2][p1][p0]
    std::map<Particle*, 
        std::map<Particle*, 
            std::map<Particle*, Triangle*> > > trianglemap;

    //  <--relaxedLength-->  
    // p0 -- stiffness -- p1 == springmap[p0][p1] == springmap[p1][p0]
    std::map<Particle*, 
        std::map<Particle*, Spring*> > springmap;

    glm::vec3 color;
    Floor* floor;
    void makeTriangle(Particle* p0, Particle* p1, Particle* p2);
    void Load(int h, int w, float paricleDistance, float stiffness, float dampness);
    void Draw(const glm::mat4& viewProjMtx, GLuint shader);
    void Move(glm::vec3& loc);
    void Update(glm::vec3& clothLoc, Air* air);
};
