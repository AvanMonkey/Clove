#pragma once
#include <glm/glm.hpp>
#include <map>

// Code adapted from LearnOpenGL (2026) https://learnopengl.com/In-Practice/Text-Rendering
/// /brief Character struct for text rendering
struct Character : Drawable{
    unsigned int TextureID;  // ID handle of the glyph texture
    glm::ivec2   Size;       // Size of glyph
    glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
    unsigned int Advance;    // Offset to advance to next glyph
};

extern std::map<char, Character> Characters;
// End of adapted code