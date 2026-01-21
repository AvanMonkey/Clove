#pragma once
#include <GLFW/glfw3.h>

class WindowSettings {
public:
	int width = 1280;

	int height = 720;

	const char* title = "Physics Engine";

	GLFWmonitor* monitor = nullptr;

	GLFWwindow* share = nullptr;

	// Used by the GLAD to set the viewport origin when mapping the framebuffer to the display window
	int lowerLeftCornerX = 0;
	int lowerLeftCornerY = 0;
};
