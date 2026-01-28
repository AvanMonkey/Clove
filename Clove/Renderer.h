#pragma once
#include "Clove.h"
#include "Shaders.h"
#include "Rectangle.h"
#include "Square.h"
#include "Pointers.h"
#define MAX_AMOUNT_OF_OBJECTS 10

// \brief calculates the velocity of an object. Currently only used for gravity
void calculateVelocity(Square* square);

/// \brief The Main Method That Renders Visuals
void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr);