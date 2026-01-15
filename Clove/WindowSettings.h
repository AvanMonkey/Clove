#pragma once
#include <GLFW/glfw3.h>

class WindowSettings {
public:
	int width = 1280;

	int height = 720;

	const char* title = "Physics Engine";

	GLFWmonitor* monitor = nullptr;

	GLFWwindow* share = nullptr;
};
