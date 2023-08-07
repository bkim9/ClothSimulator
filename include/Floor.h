#pragma once
#include "Triangle.h"


class Floor {
    public:
        Triangle* t1;
        Triangle* t2;
        float height;
        float width;
        float depth;
        glm::vec3 floorColor;
        void Init(glm::vec3 col){
            width = 5.0f;
            depth = 5.0f;
            height = -2.0f; 
            glm::vec3 center(0.f,height,0.f);
            glm::vec3 halfwidthV(width/2.0f,0.f,0.f);
            glm::vec3 halfdepthV(0.f,0.f,depth/2.0f);
        //            
        //      p0 ---- p3
        //     /  \  t2  \          
        //    /    ceter  \      ^
        //   /  t1     \  \      | halfdepthV
        //  p1  ---------- p2
        //         --> halfwidthV
            Particle* p0 = new Particle;
            Particle* p1 = new Particle;
            Particle* p2 = new Particle;
            Particle* p3 = new Particle;

            p0->Position = center - halfwidthV + halfdepthV;
            p1->Position = center - halfwidthV - halfdepthV; 
            p2->Position = center + halfwidthV - halfdepthV;          
            p3->Position = center + halfwidthV + halfdepthV;    
            p0->Normal = glm::vec3(0,1,0);
            p1->Normal = glm::vec3(0,1,0);
            p2->Normal = glm::vec3(0,1,0);
            p3->Normal = glm::vec3(0,1,0);
            p0->fixed = true;
            p1->fixed = true;
            p2->fixed = true;
            p3->fixed = true;
            t1 = new Triangle(p0,p1,p2);
            t2 = new Triangle(p2,p3,p0);
            t1->color = col;
            t2->color = col;
            t1->predraw();
            t2->predraw();
        }
        void Update(float newheight) {
            t1->color = floorColor;
            t2->color = floorColor;
            float delta_h = newheight - height;
            t1->parts[0]->Position += glm::vec3(0.f,delta_h,0.f);
            t1->parts[1]->Position += glm::vec3(0.f,delta_h,0.f);
            t1->parts[2]->Position += glm::vec3(0.f,delta_h,0.f);
            t2->parts[1]->Position += glm::vec3(0.f,delta_h,0.f);
            height = newheight;
        }
        void Draw(const glm::mat4& viewProjMtx, GLuint shader){
            t1->draw(viewProjMtx, shader);
            t2->draw(viewProjMtx, shader);
        }

};
