#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "../Clove/WindowSettings.h"
#include <iostream>
#include <thread>
#include <chrono>

/// <summary>
/// Temporary function which closes window after 10 seconds
/// </summary>
/// <param name="running"> - Is Program Running?</param>
void countdown(std::atomic<bool>& running);

