#pragma once
#include "Clove.h"

/// \brief The Main Method that Handles Vertex, Fragments & Shaders 
void renderer(GLFWwindow* window);

/// \brief Instantiate Shaders
void createShaders();

/// \brief Instantiates VBO, VAO & EBO
void objectLinker();

/// \brief Vertex Buffer Object - Stores Vertices in GPU Memory </summary>
extern unsigned int VBO;

///  \brief Vertex Array Object - Stores the setup settings for objects in GPU Memory (Vertex Positions, Colours, Etc.)
extern unsigned int VAO;

/// \brief Element Buffer Objects - Allows for indexed drawing using indices to decide which vertices to draw
extern unsigned int EBO;

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