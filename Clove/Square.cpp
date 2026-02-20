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
	// Falling
	if (fallingFlag)
	{
		positionY += velocity;
	}
	// Bouncing (as objects will bounce when they hit a surface like in real life)
	else
	{
		positionY *= decay;
		numberOfTimesBounced += 1; // This is so after the ball bounces 12 times, it comes to a stop, otherwise it would just vibrate (I genuienly can't work out a way to make this smooth so i'm doing it like this)
	}

	// Apply gravity to squares through changing the y axis of each vertices by velocity
	for (int i = 1; i < vertices.size(); i += 3)
	{
		vertices[i] -= positionY;
	}

	// Code adapted from LearnOpenGL (2026)
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);

	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_DYNAMIC_DRAW);

	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	// Enable Settings
	glEnableVertexAttribArray(vertexLocation);
	// End of adapted code


}