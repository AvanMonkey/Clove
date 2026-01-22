#pragma once
#include "Clove.h"

/// \brief The Main Method that Handles Vertex & Shaders
void renderer(GLFWwindow* window);

/// \brief Stores Vertices in GPU Memory </summary>
extern unsigned int VBO;

/// \brief Vertex Shader Source Code Written in GLSL
extern const char* vertexShaderSource;

/// \brief Shader Object
extern unsigned int vertexShader;