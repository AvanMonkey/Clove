#include "Clove.h"

//Shaders* shader; // We can't pass this into keyboard process inputs, so we will make a pointer and use that instead

void countdown(std::atomic<bool>& running) 
{
    for (int timer = 1; timer < 90 && running; timer++)
    {
        std::cout << timer << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    running = false;
}

void resizeFrameBuffer(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Tick(GLFWwindow* window, std::atomic<bool>& running)
{
    Rectangle rect;
    Pointers* ptr = new Pointers(float(xpos), float(ypos));
    glfwSetWindowUserPointer(window, ptr);

    while (!glfwWindowShouldClose(window) && running)
    {
        renderer(window, rect, ptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Free memory now that our pointers aren't used anymore (Since the simulators been closed)
    ptr->deletePointers();
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

    std::atomic <bool> running = true;

    // Temp
    std::thread t1(countdown, std::ref(running));

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Shapes will be Outlines

    Tick(window, running);

    running = false; // Ensure this flag is 0, in case the above while loop closed from the user closing the window

    // Temp
    t1.join();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}