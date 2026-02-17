#pragma once
#include "Drawable.h";
#include <iostream>
#include <random>
#define GRAVITY  0.0000003

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

		// I've used random numbers for the decay to make it more realistic. The boxes will have different bounces but still quite similar
		float min = 0.3;
		float max = 0.5;

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_real_distribution<> distr(min, max);

		// Generate a random number
		decay = distr(gen); // Decay from bounce so the box gradually comes to a standstill
	};

	~Square() = default;

	/// \brief Create a square
	void draw();

	/// \brief Update square's location based on factor's such as gravity
	void updateLocation(float deltaTime);

	/// \brief Return the object's current velocity
	float getVelocity() { return velocity; };

	/// \brief Update the object's Velocity
	void setVelocity(float newVelocity) { velocity = newVelocity; };

	/// \brief Completley stop an object
	void stopVelocity() {
		stopFlag = true;
		positionY = -positionY;
	};

	/// \brief Store the vertices of the Square
	std::vector<float> vertices;
private:

	/// Stop's falling and triggers bounce
	bool stopFlag = false;

	/// \brief If the square is grounded
	int numberOfTimesBounced = 0;

	float decay;

	/// \brief Indicates the order to draw coordinates to create a square
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief Object's Velocity
	float velocity = 0;

	/// Stores new Y position of square after velocity is applied
	float positionY = 0.0f;
};