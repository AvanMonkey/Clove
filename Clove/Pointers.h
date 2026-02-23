#pragma once
#include "Clove.h"

/// \brief Struct to hold pointers and variables that we use in GLFW callback functions where it is not possible to pass by reference. Reason for multiple pointers is because 'glfwSetWindowUserPointer' only hold's 1 pointer, 
/// so by storing all necessary pointers in a struct and pointing to this struct, we can access more than 1 pointer in callback functions.
struct InputPointers
{
	InputPointers()
	{
		shader = new Shaders(SHADER_PATH, FRAGMENT_PATH);
	}

	/// \brief Free pointers stored in struct (Needs to be done before deleting struct pointer)
	~InputPointers() {
		delete shader;
		shader = nullptr;

		for (Square* square : squaresCreated)
		{
			delete square;
		}
		squaresCreated.clear();
	};

	/// \brief Pointer to a Shader object
	Shaders* shader;

	/// \brief Holds all Square's created and their values so we can draw them all to screen as unique objects
	std::vector<Square*> squaresCreated;

	/// \brief Theme of app (Light/Dark Mode)
	bool lightMode = false;

	/// \brief Trigger a square to be drawn
	bool drawSquare = false;

	/// \brief X position of where user clicked. Used to determine square object spawn position
	double xpos = 0.0;

	/// \brief Y position of where user clicked. Used to determine square object spawn position
	double ypos = 0.0;
};