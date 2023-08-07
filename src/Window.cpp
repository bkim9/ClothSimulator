#include "Window.h"

// Window Properties
int Window::width;
int Window::height;
const char* Window::windowTitle = "Cloth Simulator";
bool Window::toggle = true;

// Objects to render
Cloth* Window::cloth;
glm::vec3 Window::cloth_loc = glm::vec3(0);
Air* Window::air;
float Window::fluidDensity = 1.225f;
float Window::dragCoefficient = 1.28f;

// Camera Properties
Camera* Cam;

// Interaction Variables
bool LeftDown, RightDown;
int MouseX, MouseY;

// The shader program id
GLuint Window::shaderProgram;

// Constructors and desctructors
bool Window::initializeProgram() {
    // Create a shader program with a vertex shader and a fragment shader.
    shaderProgram = LoadShaders("../shaders/shader.vert", "../shaders/shader.frag");
    // Check the shader program.
    if (!shaderProgram) {
        std::cerr << "Failed to initialize shader program" << std::endl;
        return false;
    }
    return true;
}


bool Window::initializeObjects() {

    cloth  = new Cloth;
    int h, w;
    float d, k, damp;
    h = 10;
    w = 10;
    d = 0.1f;
    k = 10.0f;
    damp = .001f;
    cloth_loc = glm::vec3(0);

    // height: h     width: w
    //  -   0   1   2   3   w
    //  0   o   o   o   o   o
    //  1   o   o   o   o   o     
    //  h   o   o   o   o   o
    cloth->Load(h,w,d,k,damp);

    glm::vec3 wind(0.0f,0.0f,0.0f);
    air = new Air(fluidDensity,dragCoefficient,wind);

    return true;
}

void Window::cleanUp() {
    // Deallcoate the objects.
    delete cloth;

    // Delete the shader program.
    glDeleteProgram(shaderProgram);

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}

// for the Window
GLFWwindow* Window::createWindow(int width, int height) {
    // Initialize GLFW.
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return NULL;
    }

    const char* glsl_version = "#version 150";
    // 4x antialiasing.
    glfwWindowHint(GLFW_SAMPLES, 4);

    // Apple implements its own version of OpenGL and requires special treatments
    // to make it uses modern OpenGL.
    // Ensure that minimum OpenGL version is 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Enable forward compatibility and allow a modern OpenGL context
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWmonitor* primaryMonitor = NULL; 
    // GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor(); // switch comment not full screen
    // Create the GLFW window.
    GLFWwindow* window = glfwCreateWindow(width, height, windowTitle, primaryMonitor, NULL);

    // Check if the window could not be created.
    if (!window) {
        std::cerr << "Failed to open GLFW window." << std::endl;
        glfwTerminate();
        return NULL;
    }

    // Make the context of the window.
    glfwMakeContextCurrent(window);

    // Set swap interval to 1.
    glfwSwapInterval(1);

    // set up the camera
    Cam = new Camera();
    Cam->SetAspect(float(width) / float(height));
    Cam->Update();
    
    // initialize the interaction variables
    LeftDown = RightDown = false;
    MouseX = MouseY = 0;

    // Call the resize callback to make sure things get drawn immediately.
    Window::resizeCallback(window, width, height);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    return window;
}

void Window::resizeCallback(GLFWwindow* window, int width, int height) {
#ifdef __APPLE__
    // In case your Mac has a retina display.
    glfwGetFramebufferSize(window, &width, &height);
#endif
    Window::width = width;
    Window::height = height;
    // Set the viewport size.
    glViewport(0, 0, width, height);

    Cam->SetAspect(float(width) / float(height));
}

// update and draw functions
void Window::idleCallback() {
    // Perform any updates as necessary.
    Cam->Update();
    cloth->Draw(glm::mat4(1.0f),3);
}

void Window::displayCallback(GLFWwindow* window,int argc, char* argv[]) {
    // Clear the color and depth buffers.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Gets events, including input such as keyboard and mouse or window resizing.
    glfwPollEvents();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static float clear_color[4] = { .839f,.961f,.784f, 1.0f };

    ImGui::Begin("color and air");
    {
        static float windspeed = 0.0f;
        static glm::vec3 windDir(1,0,0);
        static glm::vec3 camDir(0,0,-1);
        static vec4 dir;
        quat qRot = quat(1.f, 0.f, 0.f, 0.f);

        int show = 1;
        ImGui::Text(u8"Hello, world! ");

        ImGui::ColorEdit3("clear color", clear_color);

        // wind
        ImGui::SliderFloat("wind speed", &windspeed, -10.f, 10.f);
        vec3 light(windDir.x,windDir.y,windDir.z);
        ImGui::gizmo3D("##winddirection", light, 200, imguiGizmo::modeDirection);
        ImGui::Text(u8"wind direction");
        windDir = glm::normalize(glm::vec3(light.x,light.y,light.z));
        air->wind = windspeed * windDir;        
        ImGui::SliderFloat("fluid density", &fluidDensity, 0.f, 10.f);
        ImGui::SliderFloat("drag coefficient", &dragCoefficient, 0.f, 10.f);
        air->density = fluidDensity;
        air->dragcoef= dragCoefficient;

        // cloth
        ImGui::SliderFloat("cloth.x", &cloth_loc.x, -6.f, 6.f);
        ImGui::SliderFloat("cloth.y", &cloth_loc.y, -2.f,  6.f); // floorlevel
        ImGui::SliderFloat("cloth.z", &cloth_loc.z, -6.f, 6.f);

        // reset
        if (ImGui::Button("Reset")) {
            resetCamera();
            initializeObjects();
        }

        // if (ImGui::Button("Another Window")) show ^= 1;
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    
        ImVec2 v = ImGui::GetWindowSize();  // v = {32, 48} ,   is tool small
        ImGui::Text("%f %f", v.x, v.y);
        if (ImGui::GetFrameCount() < 10)
        printf("Frame %d: Size %f %f\n", ImGui::GetFrameCount(), v.x, v.y);
    }
    ImGui::End();

    ImGui::Begin("Camera Control");
    {
        static float camDistance = 10.f;
        static glm::vec3 camDir(0,0,-1);
        ImGui::SliderFloat("camera distance", &camDistance, .1f, 17.f);
        Cam->SetDistance(camDistance);
        vec3 camDirGizmo(camDir.x,camDir.y,camDir.z);
        ImGui::gizmo3D("##camera direction", camDirGizmo, 200, imguiGizmo::modeDirection);
        ImGui::Text("camera direction: %.3f, %.3f, %.3f", camDirGizmo.x, camDirGizmo.y, camDirGizmo.z);
        camDir = glm::normalize(glm::vec3( camDirGizmo.x, camDirGizmo.y, camDirGizmo.z));
        Cam->SetDirection(camDir);
        Cam->Update();

    // Default size: ImGui::GetFrameHeightWithSpacing()*4
    // Default mode: guiGizmo::mode3Axes|guiGizmo::cubeAtOrigin -> 3 Axes with cube @ origin
    }
    ImGui::End();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color[0] * clear_color[3], clear_color[1] * clear_color[3], clear_color[2] * clear_color[3], clear_color[3]);
    glClear(GL_COLOR_BUFFER_BIT);


    cloth->Update(cloth_loc, air);
    cloth->Draw(Cam->GetViewProjectMtx(), Window::shaderProgram);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Swap buffers.
    glfwSwapBuffers(window);
}



// helper to reset the camera
void Window::resetCamera() {
    Cam->Reset();
    Cam->SetAspect(float(Window::width) / float(Window::height));
}

// callbacks - for Interaction
void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    /*
     * TODO: Modify below to add your key callbacks.
     */

    // Check for a key press.
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                // Close the window. This causes the program to also terminate.
                glfwSetWindowShouldClose(window, GL_TRUE);
                break;
            case GLFW_KEY_R:
                resetCamera();
                break;
            case '=': // zoom in
                Cam->SetDistance(Cam->GetDistance() * 0.9f);
                Cam->Update();
                break;
            case '-': // zoom out
                Cam->SetDistance(Cam->GetDistance() * 1.1f);
                Cam->Update();
                break;            
            case GLFW_KEY_UP:
            case GLFW_KEY_DOWN:
            case GLFW_KEY_RIGHT:
            case GLFW_KEY_LEFT:
            case GLFW_KEY_U:
            case GLFW_KEY_D:
                // cloth->Update(key, air);
                break;
            case GLFW_KEY_F: // faster
                air->wind.x++;
                break;
            case GLFW_KEY_S: // slower
                air->wind.x--;
                break;
            default:
                break;
        }
    }
}

void Window::mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    // if (button == GLFW_MOUSE_BUTTON_LEFT) {
    //     LeftDown = (action == GLFW_PRESS);
    // }
    // if (button == GLFW_MOUSE_BUTTON_RIGHT) {
    //     RightDown = (action == GLFW_PRESS);
    // }
}

void Window::cursor_callback(GLFWwindow* window, double currX, double currY) {
    // int maxDelta = 100;
    // int dx = glm::clamp((int)currX - MouseX, -maxDelta, maxDelta);
    // int dy = glm::clamp(-((int)currY - MouseY), -maxDelta, maxDelta);

    // MouseX = (int)currX;
    // MouseY = (int)currY;

    // // Move camera
    // // NOTE: this should really be part of Camera::Update()
    // if (LeftDown) {
    //     const float rate = 1.0f;
    //     Cam->SetAzimuth(Cam->GetAzimuth() + dx * rate);
    //     Cam->SetIncline(glm::clamp(Cam->GetIncline() - dy * rate, -90.0f, 90.0f));
    // }
    // if (RightDown) {
    //     const float rate = 0.005f;
    //     float dist = glm::clamp(Cam->GetDistance() * (1.0f - dx * rate), 0.01f, 1000.0f);
    //     Cam->SetDistance(dist);
    // }
}