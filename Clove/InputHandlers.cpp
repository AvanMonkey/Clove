#include "InputHandlers.h"

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
		glPolygonMode(GL_FRONT_AND_BACK, fill ? GL_LINE : GL_FILL);
		fill = !fill;
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