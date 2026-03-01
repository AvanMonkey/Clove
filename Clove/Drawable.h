#pragma once
#include <vector>
#include "Objects.h"

/// \brief Draw Shapes and Objects in the Simulator
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
	unsigned int numberOfVertices = 0;

	/// \brief Vertex attribute index in Shader
	unsigned int vertexLocation = 0;

	/// \brief How many dimensions is the vector
	unsigned int vertexSize = 0;

	/// \brief The space between consectuive vertex attributes (In Bytes)
	unsigned int stride = 0; 

	/// \brief Offset in VBO
	const void* byteOffset = nullptr;

	VAO ArrayObject;
	VBO BufferObject;
	EBO ElementBufferObject;
};