#include "Clove.h"
#include "Shaders.h"
bool fill = true;

void countdown(std::atomic<bool>& running) 
{
    for (int timer = 1; timer < 16 && running; timer++)
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

void Tick(GLFWwindow* window, std::atomic<bool>& running, VAO& ArrayObject)
{
    while (!glfwWindowShouldClose(window) && running)
    {
        renderer(window, ArrayObject);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main()
{
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

    // Setup Mouse and Keyboard Inputs
    glfwSetMouseButtonCallback(window, processMouseInput);
    glfwSetKeyCallback(window, processKeyboardInput);

    std::atomic <bool> running = true;

    // Temp
    std::thread t1(countdown, std::ref(running));

    createShaders();

    // Our Objects that store data about vertices, indices and their settings in the GPU
    VAO ArrayObject;
    VBO BufferObject;
    EBO ElementBufferObject;
    objectLinker(ArrayObject, BufferObject, ElementBufferObject);

    Tick(window, running, ArrayObject);

    running = false; // Ensure this flag is 0, in case the above while loop closed from the user closing the window

    // Temp
    t1.join();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}