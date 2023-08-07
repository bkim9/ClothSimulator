////////////////////////////////////////
// Camera.h
////////////////////////////////////////

#pragma once

#include "core.h"
#include "glm/gtx/euler_angles.hpp"
#include "imGuIZMOquat.h"
#include <iostream>

// The Camera class provides a simple means to controlling the 3D camera. It could
// be extended to support more interactive controls. Ultimately. the camera sets the
// GL projection and viewing matrices.

class Camera {
public:
    Camera();

    void Update();
    void Reset();

    // Access functions
    void SetAspect(float a) { Aspect = a; }
    void SetDistance(float d) { Distance = d; }
    void SetDirection(glm::vec3 dir) {
        float tempAz = glm::atan(-dir.x/dir.z);
        SetAzimuth(glm::degrees(dir.z <0 ?
                                tempAz:
                                tempAz+glm::pi<float>()));
        SetIncline(glm::degrees(-glm::atan(dir.y/glm::sqrt(dir.z*dir.z + dir.x*dir.x))));
        std::cout << "Azimuth: " << Azimuth << ", Incline: "<< Incline << std::endl;
    }
    void SetAzimuth(float a) { Azimuth = a; }
    void SetIncline(float i) { Incline = i; }
    float GetDistance() { return Distance; }
    float GetAzimuth() { return Azimuth; }
    float GetIncline() { return Incline; }

    const glm::mat4 &GetViewProjectMtx() { return ViewProjectMtx; }

private:
    // Perspective controls
    float FOV;       // Field of View Angle (degrees)
    float Aspect;    // Aspect Ratio
    float NearClip;  // Near clipping plane distance
    float FarClip;   // Far clipping plane distance

    // Polar controls
    float Distance;  // Distance eye to origin (meters)
    float Azimuth;   // Rotation eye around Y axis (degrees)
    float Incline;   // Angle of eye over the XZ plane (degrees)
    glm::vec3 target;
    // Computed data
    glm::mat4 ViewProjectMtx;
};