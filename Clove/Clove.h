#pragma once
#define GLFW_INCLUDE_NONE
#define SHADER_PATH "vertex.vs" // vertex shader file path
#define FRAGMENT_PATH "fragment.fs" // fragment shader file path 

#include "Objects.h"
#include "WindowSettings.h"
#include "Drawable.h"
#include "Renderer.h"
#include "Shaders.h"
#include "InputHandlers.h"
#include "Rectangle.h"
#include "Square.h"
#include "Pointers.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

/// \brief Resize Frame Buffer to match window size upon resize
/// \param window Context window
/// \param width Width of the window
/// \param height Height of the window
void resizeFrameBuffer(GLFWwindow* window, int width, int height);

/// \brief Do *Blank* every frame
/// \param window Context Window
void Tick(GLFWwindow* window);