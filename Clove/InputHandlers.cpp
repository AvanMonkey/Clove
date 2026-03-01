#include "InputHandlers.h"

// Resize xpos and ypos to be in sync with the user's cursor in the window
void transformCoordinates(GLFWwindow* window, double& xpos, double& ypos)
{
	// We change the coordinates to NDC, so the xpos and ypos are in sync with screen pixels
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	// Code adapted from manon_graphics_witch (2019) https://www.reddit.com/r/GraphicsProgramming/comments/icyhqp/how_can_i_go_from_screen_coordinates_to_ndc/
	xpos = xpos / width * 2 - 1;
	ypos = ypos / height * 2 - 1;
	// End of adapted code
}

	// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void processKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Grab Shader Pointer to update look
	InputPointers* ptr = static_cast<InputPointers*>(glfwGetWindowUserPointer(window));

	// Exit window
	if (key == GLFW_KEY_F4 && action == GLFW_PRESS)
	{
		(glfwSetWindowShouldClose(window, true));
	}

	// Dark Mode to Light Mode (Vice-Versa)
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
	// End of adapted code
		ptr->shader->use();
		if (ptr->lightMode)
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			ptr->shader->setFloat("ourColour", 1.0f, 1.0f, 1.0f, 1.0f);
		}
		else
		{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			ptr->shader->setFloat("ourColour", 0.0f, 0.0f, 0.0f, 1.0f);
		}
		ptr->lightMode = !ptr->lightMode;
	}
}

// Code adapted from GLFW (2026) https://www.glfw.org/docs/3.3/input_guide.html 
void processMouseInput(GLFWwindow* window, int button, int action, int mods)
{
	// Grab Pointer to our struct holding our pointers
	InputPointers* ptr = static_cast<InputPointers*>(glfwGetWindowUserPointer(window));

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		glfwGetCursorPos(window, &ptr->xpos, &ptr->ypos);
		ptr->drawSquare = true; 
		transformCoordinates(window, ptr->xpos, ptr->ypos);
		
		Square* sqr = new Square(static_cast<float>(ptr->xpos), static_cast<float>(ptr->ypos));

		ptr->squaresCreated.push_back(sqr);
	}

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		std::cout << "Clicked Middle" << std::endl;
		ptr->drawSquare = false;
	}
}
// End of adapted code