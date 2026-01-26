#include "InputHandlers.h"

bool lightMode = false; // Start in dark mode
bool drawSquare = false;

// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void processKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	// Exit window
	if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
	{
		(glfwSetWindowShouldClose(window, true));
	}

	// Shift Polygon view (Fill and Outline)
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
// End of adapted code
		shader->use();
		if (lightMode)
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			shader->setFloat("ourColour", 1.0f, 1.0f, 1.0f, 1.0f);
		}
		else
		{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			shader->setFloat("ourColour", 0.0f, 0.0f, 0.0f, 1.0f);
		}
		lightMode = !lightMode;
	}
}

// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void processMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Clicked Left" << std::endl;
		drawSquare = true; 
	}

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		std::cout << "Clicked Middle" << std::endl;
		drawSquare = false;
	}
}
// End of adapted code