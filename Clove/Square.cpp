#include "Square.h"
#include <glad/glad.h>

void Square::draw() {

	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Square::updateLocation(float xpos, float ypos)
{
	// Add the vertices offset to the coordinates of where the user clicked so we can spawn a sqaure wherever the user clicked
	float vertices[12] =
	{
		0.025f + xpos, 0.025f - ypos, 0.0f, // Top right
		0.025f + xpos, -0.025f - ypos, 0.0f, // Bottom Right
		-0.025f + xpos, -0.025f - ypos, 0.0f, // Bottom Left
		-0.025f + xpos, 0.025f - ypos, 0.0f // Top Left
	};

	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);

	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Enable Settings
	glEnableVertexAttribArray(vertexLocation);
}