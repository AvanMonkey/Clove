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
void resizeFrameBuffer(GLFWwindow* window, int width, int height);

/// \brief Temporary function which closes window after 10 seconds
/// \param running Is Program Running?</param>
void countdown(std::atomic<bool>& running);

/// \brief Do *Blank* every frame
/// \param window Context Window
/// \param running Is Program Running?
void Tick(GLFWwindow* window, std::atomic<bool>& running);

/// \brief Is Program Running?
extern std::atomic <bool> running;

extern float deltaTime;