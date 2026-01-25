#include "InputHandlers.h"

// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Clicked" << std::endl;
	}
}

void processKeyboardInput(GLFWwindow* window)
{
	static bool waitCondition = false;  // Prevents state change from holding enter key, instead the user will have to press the Enter Key each time they wish to change state.
	bool enterKeyPressed = glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS;

	if (glfwGetKey(window, GLFW_KEY_F4) == GLFW_PRESS)
	{
		(glfwSetWindowShouldClose(window, true));
	}

	if (enterKeyPressed && !waitCondition)
	{
		glPolygonMode(GL_FRONT_AND_BACK, fill ? GL_LINE : GL_FILL);
		fill = !fill;
	}

	waitCondition = enterKeyPressed; // Make True when key is pressed so loop is not repeated until enter is pressed again.
}

void processMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Clicked" << std::endl;
	}
}