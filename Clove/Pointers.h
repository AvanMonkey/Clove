#pragma once
#include "Clove.h"

/// \brief Struct to hold pointers we use in GLFW callback functions where it is not possible to pass by reference. Reason for multiple pointers is because 'glfwSetWindowUserPointer' only hold's 1 pointer, 
/// so by storing all necessary pointers in a struct and pointing to this struct, we can access more than 1 pointer in callback functions.
struct Pointers
{
	Pointers(float xpos, float ypos)
	{
		sqr = new Square(xpos, ypos);

		shader = new Shaders(SHADER_PATH, FRAGMENT_PATH);
	}

	~Pointers() = default;

	/// \brief Free pointers stored in struct (Needs to be done before deleting struct pointer)
	void deletePointers() { delete sqr, shader; };

	/// \brief Pointer to a Square object
	Square* sqr;

	/// \brief Pointer to a Shader object
	Shaders* shader;
};