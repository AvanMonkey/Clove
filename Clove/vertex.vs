#version 330 core

// Code adapted from LearnOpenGL (2026) https://learnopengl.com/Getting-started/Shaders
layout (location = 0) in vec3 aPos;

out vec4 vertexColour; 

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vertexColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
};

// End of adapted code