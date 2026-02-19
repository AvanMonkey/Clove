#pragma once
#include "Drawable.h"
#include "Square.h"

/// \brief Draw a Rectangle
class Rectangle : public Drawable {
public:
	Rectangle() {
		numberOfVertices = 6;
		vertexLocation = 0;
		vertexSize = 3;
		stride = 3;

		vertices =
		{
		-0.2f, 0.5f, 0.0f,  // bottom-left
		 0.2f, 0.5f, 0.0f,  // bottom-right
		 0.2f, 0.7f, 0.0f,  // top-right
		-0.2f, 0.7f, 0.0f   // top-left
		};

		originalCoordinates = vertices;

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

	};
	~Rectangle() = default;

	void draw();

	void updatePosition(Square* square);

	void compression(Square* square);

	/// \brief Store the vertices of the Rectangle
	std::vector<float> vertices;

	/// \brief Store original Top Left Coordinate's Y axis to work out displacement
	std::vector<float> originalCoordinates;

	/// \brief Work out the force being applied to the object
	float getSprintConstant() { return k; };

	/// \brief update displacement
	void setDisplacement(float newX) {
		x = newX;
		overallX += newX;
	};

	/// \brief Return flag stating whether or not squares have  been cleared
	bool getClearSquaresFlag() { return clearSquares; };

	/// \brief Return flag stating whether or not squares have  been cleared
	void setClearSquaresFlag(bool value) { clearSquares = value; };

private:
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief How stiff the rectangle is
	float k = 50.0f;

	/// \brief Displacement in length from extension
	float x = 0.0f;

	/// \brief Flag stating whether or not user has cleared all squares
	bool clearSquares = false;

	/// \brief Overall displacement of the object
	float overallX = 0.0f;
};