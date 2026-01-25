#pragma once
#include "Clove.h"

/// \brief Process User Keyboard Inputs (Toggles)
/// \param window Context Window </param>
void processKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);

/// \brief Process User Mouse Inputs (Dragging Objects)
/// \param window Context Window </param>
void processMouseInput(GLFWwindow* window, int button, int action, int mods);