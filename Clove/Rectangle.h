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
	};
	~Rectangle() = default;

	void draw();

private: 
	float vertices[12] = 
	{
		0.5f, 0.4f, 0.0f, // Top right
		0.5f, 0.2f, 0.0f, // Bottom Right
		-0.5f, 0.2f, 0.0f, // Bottom Left
		-0.5f, 0.4f, 0.0f // Top Left
	};
	unsigned int indices[6] = 
	{
		0, 1, 3,
		1, 2, 3
	};

};