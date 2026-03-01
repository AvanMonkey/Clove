#pragma once
#include "Clove.h"
#include "Shaders.h"
#include "Rectangle.h"
#include "Square.h"
#include "Pointers.h"

/// \brief The Main Method That Renders Visuals
/// \param window Context window
/// \param rect Rectangle being rendered
/// \param ptr A pointer that stores multiple other pointers
/// \param deltaTime The time between frames
void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime);