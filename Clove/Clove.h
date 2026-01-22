#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glad/glad.c>
#include "../Clove/WindowSettings.h"
#include <iostream>
#include <thread>
#include <chrono>

/// <summary>
/// Resize Frame Buffer to match window size upon resize
/// </summary>
void resizeFrameBuffer(GLFWwindow* window, int width, int height);

/// <summary>
/// Temporary function which closes window after 10 seconds
/// </summary>
/// <param name="running"> - Is Program Running?</param>
void countdown(std::atomic<bool>& running);

/// <summary>
/// End Program if User Presses F4
/// </summary>
void processExitInput(GLFWwindow* window);

/// <summary>
/// Is the App Running?
/// </summary>
std::atomic <bool> running = true;

