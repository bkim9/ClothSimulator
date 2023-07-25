#pragma once

#include "Camera.h"

#include "Shader.h"
#include "core.h"
#include "Cloth.h"

class Window {
public:
    // Window Properties
    static int width;
    static int height;
    static const char* windowTitle;
    static Air* air;

    // Objects to render
    static Cloth* cloth;

    // Shader Program
    static GLuint shaderProgram;

    // Act as Constructors and desctructors
    static bool initializeProgram();
    static bool initializeObjects(int argc, char* argv[]);
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