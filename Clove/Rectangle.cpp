#include "Rectangle.h"
#include <glad/glad.h>

void Rectangle::draw() {
	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Rectangle::updatePosition(Square* square) 
{
	if (square->getApplyForce())
	{
		setDisplacement(square->getForce() / getSprintConstant());

		// Apply gravity to squares through changing the y axis of each vertices by velocity
		for (int i = 1; i < vertices.size(); i += 3)
		{
			printf("The force is: %f\n", square->getForce());
			vertices[i] -= x * -1;
		}

		ArrayObject.bindArray();
		BufferObject.bindBuffer(GL_ARRAY_BUFFER);
		ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glEnableVertexAttribArray(0);

		// Load Vertices into GPU
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

		// Settings of what the shape being drawn will look like, it's position, etc.
		glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

		// Load Indices of which Vertices to use into GPU
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Enable Settings
		glEnableVertexAttribArray(vertexLocation);

		square->setApplyForce();
	}
}

void Rectangle::compression(Square* square) 
{
	if (clearSquares)
	{
		for (int i = 1; i < vertices.size(); i += 3)
		{
			vertices[i] = originalCoordinates[i] - overallX;
		}
	}
	else if (square->getIsTouching())
	{
		for (int i = 1; i < vertices.size(); i += 3)
		{
			vertices[i] -= x;
		}

		overallX -= x; // displacement has been removed, the overall displacement decreases
	}

	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);

	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Enable Settings
	glEnableVertexAttribArray(vertexLocation);
}