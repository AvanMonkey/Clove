#pragma once
#include "Clove.h"
#include "Shaders.h"
#include "Rectangle.h"
#include "Square.h"
#include "Pointers.h"
#define GRAVITY  9

bool isColliding(Rectangle& rect, Square* sqr);

// \brief calculates the velocity of an object through deltaTime. Currently only used for gravity
void calculateVelocity(Square* square, float deltaTime);

/// \brief The Main Method That Renders Visuals
void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime);