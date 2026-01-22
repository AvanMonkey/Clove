#pragma once
#include "Clove.h"

/// \brief The Main Method that Handles Vertex, Fragments & Shaders 
void renderer(GLFWwindow* window);

/// \brief Stores Vertices in GPU Memory </summary>
extern unsigned int VBO;

///  \brief Stores the setup settings for objects in GPU Memory (Vertex Positions, Colours, Etc.)
extern unsigned int VAO;

/// \brief Vertex Shader Source Code Written in GLSL
extern const char* vertexShaderSource;

/// \brief Vertex Shader Object
extern unsigned int vertexShader;

/// \brief Fragment Shader Source Code Written in GLSL
extern const char* fragmentShaderSource; 

/// \brief Fragment Shader Object
extern unsigned int fragmentShader;

/// \brief Combine Vertex & Fragment Shaders to Render Objects
extern unsigned int shaderProgram;