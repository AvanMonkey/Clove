#pragma once
#include "Clove.h"

/// \brief Transform given coordinates to be compatible with a GLFW window
/// \param window Context Window
/// \param xpos X-Axis coordinate
/// \param ypos Y-Axis coordinate
void transformCoordinates(GLFWwindow* window, double& xpos, double& ypos);

/// \brief Process User Keyboard Inputs (Toggles)
/// \param window Context Window
/// \param key Key being operated on
/// \param scancode Hardware code for a key
/// \param action Key action
/// \param mods Modifier key state
void processKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);

/// \brief Process User Mouse Inputs (Dragging Objects)
/// \param window Context Window
/// \param button Button being operated on
/// \param action Action being performed
/// \param mods Modifier key state
void processMouseInput(GLFWwindow* window, int button, int action, int mods);