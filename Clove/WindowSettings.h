#pragma once
#include <GLFW/glfw3.h>

/// \brief Settings given to the window that will be used to display the GUI
struct WindowSettings {
	int width = 1280;

	int height = 720;

	char title[50] = "Physics Engine";

	GLFWmonitor* monitor = nullptr;

	GLFWwindow* share = nullptr;

	// Used by the GLAD to set the viewport origin when mapping the framebuffer to the display window
	int lowerLeftCornerX = 0;
	int lowerLeftCornerY = 0;

};
