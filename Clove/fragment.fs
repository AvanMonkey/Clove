#version 330 core
// Code adapted from LearnOpenGL (2026)
out vec4 FragColour; // output colour of Shape

uniform vec4 ourColour; // import colour of Shape from OpenGL
void main()
{
    FragColour = ourColour;
}
// End of adapted code