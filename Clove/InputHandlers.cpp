#include "InputHandlers.h"

bool lightMode = false; // Start in dark mode

// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void processKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
// End of adapted code

	// Exit window
	if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
	{
		(glfwSetWindowShouldClose(window, true));
	}

	// Shift Polygon view (Fill and Outline)
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
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
		std::cout << "Clicked" << std::endl;
	}
}
// End of adapted code