#pragma once
#include "Clove.h"
#include "Shaders.h"

/// \brief The Main Method That Renders Visuals
void renderer(GLFWwindow* window, VAO& ArrayObject, Shaders& shader);

/// \brief Instantiates VBO, VAO & EBO
void objectLinker(VAO& ArrayObject, VBO& BufferObject, EBO& ElementBufferObject);

// \brief Shape's Fill Property
extern bool fill;