#include "Clove.h"

void resizeFrameBuffer(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Tick(GLFWwindow* window)
{
    float lastTick = static_cast<float>(clock());
    float deltaTime = 0;
    float fps = 0;
    int fpsInt = 0; // Just used to transform the fps to an int so we can dont display decimal places
    Rectangle rect;
    InputPointers* ptr = new InputPointers();
    glfwSetWindowUserPointer(window, ptr);

    // Code adapted from GLFW (2026) https://www.glfw.org/docs/3.0/group__time.html
    double start_time = glfwGetTime();
    // End of adapted code

    while (!glfwWindowShouldClose(window))
    {
        deltaTime = (clock() - lastTick) / CLOCKS_PER_SEC;
        lastTick = static_cast<float>(clock());
        renderer(window, rect, ptr, deltaTime);

        // Update fps display once every second (hence Frames per second)
        if (glfwGetTime() - start_time >= 1.0)
        {
            fps = 1 / deltaTime;
            fpsInt = static_cast<int>(fps);

            start_time = glfwGetTime();
            printf("\nFPS updated\n");
        }

        std::string fpsTitle = "Physics Engine          FPS: " + std::to_string(fpsInt) + "         Number of objects: " + std::to_string(ptr->squaresCreated.size()) + " | 30";
        glfwSetWindowTitle(window, fpsTitle.c_str());

        glfwSwapBuffers(window);
        glfwPollEvents();
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

    // Start tick loop (main program)
    Tick(window);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}