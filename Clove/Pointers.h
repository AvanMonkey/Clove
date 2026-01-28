#pragma once
#include "Clove.h"

/// \brief Struct to hold pointers we use in GLFW callback functions where it is not possible to pass by reference. Reason for multiple pointers is because 'glfwSetWindowUserPointer' only hold's 1 pointer, 
/// so by storing all necessary pointers in a struct and pointing to this struct, we can access more than 1 pointer in callback functions.
struct InputPointers
{
	InputPointers(float xpos, float ypos)
	{
		shader = new Shaders(SHADER_PATH, FRAGMENT_PATH);
	}

	~InputPointers() = default;

	/// \brief Free pointers stored in struct (Needs to be done before deleting struct pointer)
	void deletePointers() { shader; };

	/// \brief Pointer to a Shader object
	Shaders* shader;

	/// \brief Holds all Square's created and their values so we can draw them all to screen as unique objects
	std::vector<Square*> squaresCreated;
};