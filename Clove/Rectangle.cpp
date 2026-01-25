#include "Rectangle.h"
#include <glad/glad.h>

void Rectangle::draw() {
	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);
	// Enable Settings
	glEnableVertexAttribArray(0);
	// Draw
	glDrawElements(GL_TRIANGLE_STRIP, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}