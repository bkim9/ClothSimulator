#pragma once

#include "Camera.h"
#include "Shader.h"
#include "Cloth.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


class Window {
public:
    // Window Properties
    static int width;
    static int height;
    static const char* windowTitle;
    static bool toggle;
    // static ImVec4 clear_color;
    static Air* air;
    static float fluidDensity;
    static float dragCoefficient;

    // Objects to render
    static Cloth* cloth;
    static glm::vec3 cloth_loc;

    // Shader Program
    static GLuint shaderProgram;

    // Act as Constructors and desctructors
    static bool initializeProgram();
    static bool initializeObjects();
    static void cleanUp();

    // for the Window
    static GLFWwindow* createWindow(int width, int height);
    static void resizeCallback(GLFWwindow* window, int width, int height);

    // update and draw functions
    static void idleCallback();
    static void displayCallback(GLFWwindow*,int argc, char* argv[]);


    // helper to reset the camera
    static void resetCamera();

    // callbacks - for interaction
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_callback(GLFWwindow* window, double currX, double currY);
};