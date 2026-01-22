#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "WindowSettings.h"
#include "Vertex.h"
#include "Renderer.h"
#include <iostream>
#include <thread>
#include <chrono>

/// \brief Resize Frame Buffer to match window size upon resize
void resizeFrameBuffer(GLFWwindow* window, int width, int height);

/// \brief Temporary function which closes window after 10 seconds
/// \param running Is Program Running?</param>
void countdown(std::atomic<bool>& running);

/// \brief End Process should user press exit key
/// \param window Context Window </param>
void processExitInput(GLFWwindow* window);

/// \brief Is Program Running?
extern std::atomic <bool> running;

