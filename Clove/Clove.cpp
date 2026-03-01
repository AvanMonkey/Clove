#include "Clove.h"

void resizeFrameBuffer(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Tick(GLFWwindow* window)
{
    float lastTick = clock();
    float deltaTime = 0;
    float fps = 0;
    // Code adapted from GLFW (2026) https://www.glfw.org/docs/3.0/group__time.html
    double start_time = glfwGetTime();
    // End of adapted code
    Rectangle rect;
    InputPointers* ptr = new InputPointers();
    glfwSetWindowUserPointer(window, ptr);
    while (!glfwWindowShouldClose(window))
    {
        deltaTime = (clock() - lastTick) / CLOCKS_PER_SEC;
        lastTick = clock();
        renderer(window, rect, ptr, deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetTime() - start_time >= 1.0)
        {
            fps = 1 / deltaTime;
            int fpsInt = static_cast<int>(fps);          // round FPS to integer
            std::string fpsTitle = "Physics Engine      FPS: " + std::to_string(fpsInt);
            glfwSetWindowTitle(window, fpsTitle.c_str()); // pass as const char* to GLFW

            glfwSetWindowTitle(window, fpsTitle.c_str());
            start_time = glfwGetTime();
            printf("FPS updated\n");
        }
    }
    // Free memory now that our pointers aren't used anymore (Since the simulators been closed)
    delete ptr;
}

int main()
{
        // Code adapted from LearnOpenGL (2026)
  
    // GLFW Window Initiation
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to Startup");
    }

    WindowSettings Settings = WindowSettings();

    GLFWwindow* window = glfwCreateWindow(Settings.width, Settings.height, Settings.title, Settings.monitor, Settings.share);

    if (window == NULL)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize Window");
    }
    glfwMakeContextCurrent(window);

    // GLAD Initiation (Manages Function Pointers)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // 'glfwGetProcAddress' Allows for Portability across different OS
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    // Set Default Cursor to crosshair
    try
    {
        GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
        glfwSetCursor(window, cursor);
    }
    catch (const std::exception& e)
    {
        throw e;
    }
    // Setup Window Settings
    glViewport(Settings.lowerLeftCornerX, Settings.lowerLeftCornerY, Settings.width, Settings.height);
    glfwSetFramebufferSizeCallback(window, resizeFrameBuffer);

        // End of adapted code

    // Setup Mouse and Keyboard Inputs
    glfwSetMouseButtonCallback(window, processMouseInput);
    glfwSetKeyCallback(window,  processKeyboardInput);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Shapes will be Outlines

    Tick(window);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}