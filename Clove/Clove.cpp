#include "Clove.h"

void countdown(std::atomic<bool>& running) 
{
    for (int i = 1; i < 11 && running; i++)
    {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    running = false;
}

void resizeFrameBuffer(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processExitInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_F4) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    // GLFW Window Initiation
    if (!glfwInit())
    {
        std::cout << "Startup Error has occured";
        return 1;
    }

    WindowSettings Settings = WindowSettings();

    GLFWwindow* window = glfwCreateWindow(Settings.width, Settings.height, Settings.title, Settings.monitor, Settings.share);

    if (window == NULL)
    {
        std::cout << "Window failed to instantiate" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD Initiation (Manages Function Pointers)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // 'glfwGetProcAddress' Allows for Portability across different OS
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(Settings.lowerLeftCornerX, Settings.lowerLeftCornerY, Settings.width, Settings.height);
    glfwSetFramebufferSizeCallback(window, resizeFrameBuffer);

    std::atomic <bool> running = true;

    std::thread t1(countdown, std::ref(running));
    
    createShaders();
    objectLinker();

    // Tick 
    while (!glfwWindowShouldClose(window) && running)
    {
        processExitInput(window);

        renderer(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    running = false; // Ensure this flag is 0, in case the above while loop closed from the user closing the window

    t1.join();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}