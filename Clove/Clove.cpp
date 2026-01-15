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

int main()
{
    WindowSettings Settings = WindowSettings();

    if (!glfwInit())
    {
        std::cout << "Startup Error has occured";
        return 1;
    }
    std::atomic <bool> running = true;

    GLFWwindow* window = glfwCreateWindow(Settings.width, Settings.height, Settings.title, Settings.monitor, Settings.share);

    std::thread t1(countdown, std::ref(running));
    
    // Frames
    while (!glfwWindowShouldClose(window) && running)
    {
        glfwPollEvents();
        glfwSwapBuffers(window);  
    }

    running = false; // Ensure this flag is 0, incase the above while loop closed from the user closing the window

    t1.join();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}