#pragma once
#include "Clove.h"

/// \brief The Main Method That Renders Visuals
void renderer(GLFWwindow* window, VAO& ArrayObject);

/// \brief Instantiate Shaders
void createShaders();

/// \brief Instantiates VBO, VAO & EBO
void objectLinker(VAO& ArrayObject, VBO& BufferObject, EBO& ElementBufferObject);

/// \brief Vertex Shader Source Code Written in GLSL
extern const char* vertexShaderSource;

/// \brief Colour the Shape Written in GLSL
extern const char* fragmentShaderSource; 

/// \brief Combine Vertex & Fragment Shaders to Render Objects
extern unsigned int shaderProgram;

// \brief Offset Between elements in EBO
extern const void* byteOffset;

// \brief Shape's Fill Property
extern bool fill;