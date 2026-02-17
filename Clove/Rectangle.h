#pragma once
#include "Drawable.h"

/// \brief Draw a Rectangle
class Rectangle : public Drawable {
public:
	Rectangle() {
		numberOfVertices = 6;
		vertexLocation = 0;
		vertexSize = 3;
		stride = 3;

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

		float vertices[12] = {
		-0.2f, -0.9f, 0.0f,  // bottom-left
		 0.2f, -0.9f, 0.0f,  // bottom-right
		 0.2f, -0.7f, 0.0f,  // top-right
		-0.2f, -0.7f, 0.0f   // top-left
		};

	};
	~Rectangle() = default;

	void draw();

	float vertices[12] = {
	-0.2f, -0.9f, 0.0f,  // bottom-left
	 0.2f, -0.9f, 0.0f,  // bottom-right
	 0.2f, -0.7f, 0.0f,  // top-right
	-0.2f, -0.7f, 0.0f   // top-left
	};

private: 
	unsigned int indices[6] = 
	{
		0, 1, 3,
		1, 2, 3
	};
};