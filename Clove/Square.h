#pragma once
#include "Drawable.h";
#include <iostream>
#define SPEED  0.0008

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
	};

	~Square() = default;

	/// \brief Create a square
	void draw();

	/// \brief Update square's location based on factor's such as gravity
	void updateLocation();

	/// \brief Return the object's current velocity
	float getVelocity() { return velocity; };

	/// \brief Update the object's Velocity
	void setVelocity(float newVelocity) { 
		velocity = newVelocity;
		std::cout << "Current Velocity: " << velocity << std::endl;
	};
private:
	/// \brief Store the vertices of the Square
	std::vector<float> vertices;

	/// \brief Indicates the order to draw coordinates to create a square
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief Object's Velocity
	float velocity = 0;
};