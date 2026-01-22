#pragma once
#include <glad/glad.h>

/// \brief Base class for Object classes that will store data inside the GPU for rendering
class Objects
{
public:
	virtual ~Objects() = default; // Allows child classes to destroy both the Objects class and themselves

	void bindBuffer(GLenum type) {
		glBindBuffer(type, id); 
	};
protected:
	unsigned int id = 0;
};

/// \brief Vertex Buffer Object - Stores Vertices in GPU Memory </summary>
class VBO : public Objects
{
public:
	VBO() { glGenBuffers(1, &id); };
	~VBO() = default;
};

/// \brief Element Buffer Objects - Allows for indexed drawing using indices to decide which vertices to draw
class EBO : public Objects
{
public:
	EBO() { glGenBuffers(1, &id); };
	~EBO() = default;
};

///  \brief Vertex Array Object - Stores the setup settings for objects in GPU Memory (Vertex Positions, Colours, Etc.)
class VAO : Objects
{
public:
	VAO() { glGenVertexArrays(1, &id); };
	~VAO() = default;

	void bindArray() { glBindVertexArray(id); };
};