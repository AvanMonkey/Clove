#include "Square.h"
#include <glad/glad.h>
#include <iostream>

void Square::draw() {

	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Square::updateLocation()
{
	std::vector<float> objectVertices = vertices;
	positionY += velocity;

	/*for (int i = 0; i < (sizeof(vertices) / sizeof(vertices[0])); i += 3)
	{
		vertices[i] += velocity;
	}*/

	// Apply gravity to squares through changing the y axis of each vertices by velocity
	for (int i = 1; i < vertices.size(); i += 3)
	{
		objectVertices[i] -= positionY;
	}

	// Code adapted from LearnOpenGL (2026)
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);

	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, objectVertices.size() * sizeof(objectVertices[0]), objectVertices.data(), GL_DYNAMIC_DRAW);

	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	// Enable Settings
	glEnableVertexAttribArray(vertexLocation);
	// End of adapted code
}