#pragma once
#include <vector>
#include "Objects.h"

/// Draw Shapes and Objects in the Simulator
class Drawable {
public:
	virtual ~Drawable() {}
	void draw();
protected:
	/// \brief Shape Corners
	std::vector<float> vertices;

	/// \brief Use to select specific vertices to draw
	std::vector<unsigned int> indices;

	/// \brief How many Vertices we wish to draw
	unsigned int numberOfVertices;

	/// \brief Vertex attribute index in Shader
	unsigned int vertexLocation;

	/// \brief How many dimensions is the vector
	unsigned int vertexSize;

	/// \brief The space between consectuive vertex attributes (In Bytes)
	unsigned int stride; 

	/// \brief Offset in VBO
	const void* byteOffset = nullptr;

	VAO ArrayObject;
	VBO BufferObject;
	EBO ElementBufferObject;
};