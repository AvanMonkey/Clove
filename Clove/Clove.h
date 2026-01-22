#pragma once
#define GLFW_INCLUDE_NONE
#include "Objects.h"
#include "WindowSettings.h"
#include "Vertex.h"
#include "Renderer.h"
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
void Tick(GLFWwindow* window, std::atomic<bool>& running, VAO& ArrayObject);

/// \brief Is Program Running?
extern std::atomic <bool> running;

