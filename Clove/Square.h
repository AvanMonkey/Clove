#pragma once
#include "Drawable.h"

/// \brief Draw a Rectangle
class Square : public Drawable {
public:
	Square(float xpos, float ypos) {
		numberOfVertices = 6;
		vertexLocation = 0;
		vertexSize = 3;
		stride = 3;

		// Add the vertices offset to the coordinates of where the user clicked so we can spawn a sqaure wherever the user clicked
		vertices =
		{
			0.015f + xpos, 0.025f - ypos, 0.0f, // Top right
			0.015f + xpos, -0.025f - ypos, 0.0f, // Bottom Right
			-0.015f + xpos, -0.025f - ypos, 0.0f, // Bottom Left
			-0.015f + xpos, 0.025f - ypos, 0.0f // Top Left
		};

		// Code adapted from LearnOpenGL (2026)
		ArrayObject.bindArray();
		BufferObject.bindBuffer(GL_ARRAY_BUFFER);
		ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glEnableVertexAttribArray(0);

		// Load Vertices into GPU
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);

		// Settings of what the shape being drawn will look like, it's position, etc.
		glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

		// Load Indices of which Vertices to use into GPU
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// Enable Settings
		glEnableVertexAttribArray(vertexLocation);
		// End of adapted code
	};

	~Square() = default;

	void draw();

	void updateLocation();

	float getVelocity() { return this->velocity; };

	void setVelocity(float newVelocity) { velocity = newVelocity; };
private:
	std::vector<float> vertices;

	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	float velocity = 0;
};