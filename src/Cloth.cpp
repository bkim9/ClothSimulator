#include "Cloth.h"


void Cloth::makeTriangle(Particle *p0, Particle *p1, Particle *p2) {
    trianglemap[p0][p1][p2] = new Triangle(p0,p1,p2);
    trianglemap[p0][p2][p1] = trianglemap[p0][p1][p2];
    trianglemap[p1][p0][p2] = trianglemap[p0][p1][p2];
    trianglemap[p1][p2][p0] = trianglemap[p0][p1][p2]; 
    trianglemap[p2][p0][p1] = trianglemap[p0][p1][p2];
    trianglemap[p2][p1][p0] = trianglemap[p0][p1][p2];
}

void Cloth::Load(int h, int w, float particleDistance, float stiffness, float dampness)
{
    // height: h     width: w
    //  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    // | x = 0            -> z         |
    // |                    j          |
    // |            0   1   2   3   w  |
    // | |      0   -   -   -   -   -  |
    // | v  i   1   o   o   x   o   o  |
    // | y      h   o   o   o   o   o  |
    // ㄴㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    
    height = h;
    width = w;
    particledistance = particleDistance;

    Particle* default_value = nullptr;
    verticies.resize(h+1, std::vector<Particle*>(w+1, default_value));

    // filling in vertices
    for ( int i = 0; i < h+1; i++) {
        for ( int j = 0; j < w+1; j++ ) {
            float r = .1;
            verticies[i][j] = new Particle;
            verticies[i][j]->Mass = .01; // 10 g 
            verticies[i][j]->Position = glm::vec3(0, i * particleDistance, j * particleDistance) + r * verticies[i][j]->RandomVector();
            verticies[i][j]->Velocity = r * verticies[i][j]->RandomVector();
            verticies[i][j]->fixed = i == 0;
        }
    }

    // Spring (smaller)
    for ( int i = 0 ; i < h; i++ ){
        for ( int j = 0; j < w; j++ ) {
            //    [i][j]  -  [i][j+1]
            //       |    X
            //    [i+1][j]   [i+1][j+1]
            springmap[verticies[i][j]]  [verticies[i][j+1]] = new Spring(verticies[i][j],verticies[i][j+1],stiffness, dampness, particleDistance);
            springmap[verticies[i][j+1]][verticies[i][j]  ] = springmap[verticies[i][j]]  [verticies[i][j+1]];
            
            springmap[verticies[i][j+1]][verticies[i+1][j]] = new Spring(verticies[i][j+1],verticies[i+1][j], stiffness, dampness, particleDistance * glm::sqrt(2));
            springmap[verticies[i+1][j]][verticies[i][j+1]] = springmap[verticies[i][j+1]][verticies[i+1][j]];
            
            springmap[verticies[i+1][j]][verticies[i][j]] = new Spring(verticies[i+1][j],verticies[i][j], stiffness, dampness, particleDistance );
            springmap[verticies[i][j]][verticies[i+1][j]] = springmap[verticies[i+1][j]][verticies[i][j]];

            springmap[verticies[i][j]]  [verticies[i+1][j+1]] = new Spring(verticies[i][j], verticies[i+1][j+1], stiffness, dampness, particleDistance * glm::sqrt(2));
            springmap[verticies[i+1][j+1]]  [verticies[i][j]] = springmap[verticies[i][j]]  [verticies[i+1][j+1]];

            //     [i][j]     [i][j+1]
            //                    |
            //    [i+1][j]   [i+1][j+1]
            if ( j == w-1 ) {
                springmap[verticies[i][j+1]][verticies[i+1][j+1]] = new Spring(verticies[i][j+1],verticies[i+1][j+1],stiffness, dampness, particleDistance);
                springmap[verticies[i+1][j+1]][verticies[i][j+1]] = springmap[verticies[i][j+1]][verticies[i+1][j+1]];
            }

            //     [i][j]     [i][j+1]
            //                    
            //    [i+1][j] - [i+1][j+1]
            if ( i == h-1 ) {
                springmap[verticies[i+1][j]][verticies[i+1][j+1]] = new Spring(verticies[i+1][j],verticies[i+1][j+1],stiffness, dampness, particleDistance) ;
                springmap[verticies[i+1][j+1]][verticies[i+1][j]] = springmap[verticies[i+1][j]][verticies[i+1][j+1]];
            }
        }
    }

    // Spring (LARGER)
    for ( int i = 0 ; i < h-1; i++ ){
        for ( int j = 0; j < w-1; j++ ) {
            //    [i][j]   -  [i][j+2]
            //       |     X
            //    [i+2][j]  [i+2][j+2]
            springmap[verticies[i][j]]  [verticies[i][j+2]] = new Spring(verticies[i][j], verticies[i][j+2], stiffness, dampness, particleDistance * 2);
            springmap[verticies[i][j+2]]  [verticies[i][j]] = springmap[verticies[i][j]]  [verticies[i][j+2]];

            springmap[verticies[i][j+2]][verticies[i+2][j]] = new Spring(verticies[i][j+2],verticies[i+2][j], stiffness, dampness, particleDistance * 2 * sqrt(2));
            springmap[verticies[i+2][j]][verticies[i][j+2]] = springmap[verticies[i][j+2]][verticies[i+2][j]];

            springmap[verticies[i+2][j]][verticies[i][j]  ] = new Spring(verticies[i+2][j],verticies[i][j] , stiffness, dampness, particleDistance * 2);
            springmap[verticies[i][j]  ][verticies[i+2][j]] = springmap[verticies[i+2][j]][verticies[i][j]  ];
            
            springmap[verticies[i][j]][verticies[i+2][j+2]] = new Spring(verticies[i][j], verticies[i+2][j+2], stiffness, dampness, particleDistance * 2 * sqrt(2));
            springmap[verticies[i+2][j+2]][verticies[i][j]] = springmap[verticies[i][j]][verticies[i+2][j+2]];

            //     [i][j]     [i][j+2]
            //                    |
            //    [i+2][j]   [i+2][j+2]
            if ( j >= w-3 ) {
                springmap[verticies[i][j+2]][verticies[i+2][j+2]] = new Spring(verticies[i][j+2],verticies[i+2][j+2], stiffness, dampness, particleDistance * 2);
                springmap[verticies[i+2][j+2]][verticies[i][j+2]] = springmap[verticies[i][j+2]][verticies[i+2][j+2]];
            }

            //     [i][j]     [i][j+2]
            //                    
            //    [i+2][j] - [i+2][j+2]
            if ( i >= h-3 ) {
                springmap[verticies[i+2][j]][verticies[i+2][j+2]] = new Spring(verticies[i+2][j],verticies[i+2][j+2], stiffness, dampness, particleDistance * 2);
                springmap[verticies[i+2][j+2]][verticies[i+2][j]] = springmap[verticies[i+2][j]][verticies[i+2][j+2]];
            }
        }
    }

    // Triangles
    for ( int i = 0 ; i < h; i++ ){
        for ( int j = 0; j < w; j++ ) {
            if ((i + j) % 2 == 0) {
                //    [i][j]  -  [i][j+1]
                //       |    /    |
                //   [i+1][j] - [i+1][j+1]
                makeTriangle(verticies[i][j], verticies[i][j+1], verticies[i+1][j]);
                makeTriangle(verticies[i+1][j+1], verticies[i][j+1], verticies[i+1][j]);
            } else {
                //    [i][j]   -  [i][j+1]
                //       |     \    |
                //    [i+1][j] - [i+1][j+1]
                makeTriangle( verticies[i][j], verticies[i][j+1], verticies[i+1][j+1]);
                makeTriangle( verticies[i][j], verticies[i+1][j], verticies[i+1][j+1]);
            }
        }
    }

    // Particle normals
    for (auto it : trianglemap) {
        glm::vec3 subnormal(0);
        // it.first
        for (auto jt : it.second) {
            for(auto kt: jt.second) {
                if (glm::dot( glm::vec3(1,0,0), kt.second->normal) < 0) kt.second->normal = -kt.second->normal;
                subnormal += kt.second->normal;
            }
        }
        // if (glm::dot( glm::vec3(1,0,0), subnormal) < 0) subnormal = -subnormal;
        it.first->Normal = glm::normalize(subnormal);// / it.second.size();
        
    }

    // Triangle predraw
    for (auto it : trianglemap ) {
        for( auto jt : it.second) {
            for( auto kt : jt.second) {
                kt.second->predraw();
            }
        }
    }
    // filling in vertices degree
    for ( int i = 0; i < h+1; i++) {
        for ( int j = 0; j < w+1; j++ ) {
            verticies[i][j]->degree = trianglemap[verticies[i][j]].size();
        }
    }
}

void Cloth::Draw(const glm::mat4 &viewProjMtx, GLuint shader) {
    // trianglemap [i]->draw(viewProjMtx, shader);
    for (auto i : trianglemap) {
        for ( auto j : i.second) {
            for( auto k: j.second) {
                k.second->draw(viewProjMtx, shader);
            }
        }
    }
}

void Cloth::Update(int movedirection, Air* air) {
    glm::vec3 step(0);
    float stepsize = particledistance;
    switch ( movedirection ) {
        case GLFW_KEY_UP:
            step.z = stepsize;
            break;
        case GLFW_KEY_LEFT:
            step.x = -stepsize;
            break;
        case GLFW_KEY_DOWN:
            step.z = -stepsize;
            break;
        case GLFW_KEY_RIGHT:
            step.x = stepsize;
            break;
        case GLFW_KEY_U:
            step.y = stepsize;
            break;
        case GLFW_KEY_D:
            step.y = -stepsize;
            break;
        default:
            break;
    }
    for( int j = 0; j < width+1 && glm::length(step) != 0; j++ ) {
        verticies[0][j]->Position += step;
    }

    // Evaluate all forces in current configuration at time tn and use these to compute all accelerations
        // gravity
        for (auto i: verticies) {
            for (auto j: i) {
                glm::vec3 gravity(0, j->Mass * -9.8f, 0);
                j->ApplyForce(gravity);
            }
        }
        // Spring
        for (auto i: springmap) {
            for(auto j: i.second) {
                j.second->Applyforce(); // Spring applied twice? apply to only the particle specified
            }
         }
        // Aerodynamic
        for (auto it: trianglemap) {
            for(auto jt: it.second) {
                for(auto kt: jt.second) {
                    kt.second->Aero(air);
                }
            }
        }

    // Integrate accelerations over some finite time step delta t to advance everything to new positions( and velocities ) at new time tn+1
    float deltatime = 0.01f;
    for( int i = 1; i < height+1; i++ ) {
        for( int j = 0; j<width+1; j++ ) {
            verticies[i][j]->Integrate(deltatime);
        }
    }

    // Update normals
    // Particle normals
    for (auto it : trianglemap) {
        glm::vec3 subnormal(0);
        // it.first
        for (auto jt : it.second) {
            for(auto kt: jt.second) {
                subnormal += kt.second->normal;
                kt.second->getN();
            }
        }
        it.first->Normal = glm::normalize(subnormal);// / it.second.size();
    }

    // collision handling with y = -2 plane
    float collisionconstant = .2;
    for(auto i : verticies){
        for( auto j : i) {
            if( j->Position.y < -2 && j->Velocity.y < 0){
                j->Velocity.y = -j->Velocity.y * collisionconstant;
                if( j->Position.y < -2.2 ) j->Position.y = -2.2 + .001 * j->RandomVector().y;
            } 
        }
    }
}
