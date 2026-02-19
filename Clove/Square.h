#pragma once
#include "Drawable.h";
#include <iostream>
#include <random>
#define GRAVITY  0.09

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

		numberOfTimesBounced = 0;
	};

	~Square() = default;

	/// \brief Create a square
	void draw();

	/// \brief Update square's location based on factor's such as gravity
	void updateLocation();

	/// \brief Add bounce to object through inverting position
	void addBounce() { positionY = -positionY; };

	/// \brief Store the vertices of the Square
	std::vector<float> vertices;


	/// \brief Return object's weight
	float getMass() { return mass; };

	/// \brief Set object's force
	void setForce(float newForce) { force = newForce; };

	/// \brief Return object's force
	float getForce() { return force; };

	/// \brief Set flag to apply object's mass or not to rectangle
	void setApplyForce() { applyForce = !applyForce; };

	/// \brief Get Flag stating whether or not to apply mass to rectangle
	bool getApplyForce() { return applyForce; };

	void setFallingFlag(bool newFlag) { fallingFlag = newFlag; };

	bool getFallingFlag() { return fallingFlag; };

	void setNumberOfTimesBounced() { numberOfTimesBounced += 1; };

	int getNumberOfTimesBounced() { return numberOfTimesBounced; };

	/// \brief Return the object's current velocity
	float getVelocity() { return velocity; };

	/// \brief Update the object's Velocity
	void setVelocity(float newVelocity) { velocity = newVelocity; };

	void setIsTouching() { isTouching = !isTouching; };

	bool getIsTouching() { return isTouching; };

private:

	float decay;

	/// \brief Indicates the order to draw coordinates to create a square
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief Stores new Y position of square after velocity is applied
	float positionY = 0.0f;

	/// \brief Each Square has a mass given to it. This weight is used to work out it's falling velocity.
	float mass = 1.4f;

	/// \brief The force a square exerts
	float force = 0.0f;

	/// \brief Flag to show whether or not a square can apply force (Will be false after collision to prevent force being applied multiple times)
	bool applyForce = true;

	/// States whether or not square is falling
	bool fallingFlag = false;

	/// \brief If the square is grounded
	int numberOfTimesBounced;

	/// \brief Object's Velocity
	float velocity = 0;

	bool isTouching = false;
};