#pragma once
#include "Drawable.h"
#include <iostream>
#include <random>
#include <glad/glad.h>
#define MAX_AMOUNT_OF_OBJECTS 30
#define GRAVITY  9

class Rectangle;  // Forward Declaration

/// \brief Draw a Square
class Square : public Drawable {
public:
	Square(float xpos, float ypos) {
		numberOfVertices = 6;
		vertexLocation = 0;
		vertexSize = 3;
		stride = 3;

		// Add the vertices offset to the coordinates of where the user clicked so we can spawn a sqaure wherever the user clicked
		std::vector<float> verticesValues =
		{
			0.015f + xpos, 0.025f - ypos, 0.0f, // Top right
			0.015f + xpos, -0.025f - ypos, 0.0f, // Bottom Right
			-0.015f + xpos, -0.025f - ypos, 0.0f, // Bottom Left
			-0.015f + xpos, 0.025f - ypos, 0.0f // Top Left
		};

		setVertices(verticesValues);

		// I've used random numbers for the decay to make it more realistic. The boxes will have different bounces but still quite similar
		double min = 0.3;
		double max = 0.5;

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_real_distribution<> distr(min, max);

		// Generate a random number
		setDecay(static_cast<float>(distr(gen))); // Decay from bounce so the box gradually comes to a standstill
	};

	~Square() = default;
	/// \brief Create a square
	void draw();

	/// \brief Calculates the velocity of an object and it's force.
	void calculateVelocity(float deltaTime);

	/// \brief Collision detection for when the object touches an rectangle object. (In Clove it'll be the platform)
	bool isColliding(Rectangle& rect);

	/// \brief Update square's location based on factor's such as gravity
	void updateLocation();

	/// \brief Add bounce to object through inverting position
	void addBounce() { positionY = -positionY; };

	/// \brief Return reference to vertices vector for general modification uses
	std::vector<float>& getVertices() { return vertices; };

	/// \brief Set coordinates of object's vertices
	void setVertices(std::vector<float> newVertices) { vertices = newVertices; };

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

	/// \brief Set Flag stating whether or not object is falling
	void setFallingFlag(bool newFlag) { fallingFlag = newFlag; };

	/// \brief Get Flag stating whether or not object is falling
	bool getFallingFlag() { return fallingFlag; };

	/// \brief Get the number of times the object has bounced
	int getNumberOfTimesBounced() { return numberOfTimesBounced; };

	/// \brief Increment number of times the object has bounced
	void incrementNumberOfTimesBounced() { numberOfTimesBounced += 1; };

	/// \brief Return the object's current velocity
	float getVelocity() { return velocity; };

	/// \brief Update the object's Velocity
	void setVelocity(float newVelocity) { velocity = newVelocity; };

	/// \brief Set a flag to determine whether or not a square is touching the platform
	void setIsTouching() { isTouching = !isTouching; }
	
	/// \brief Set the object's bounce decay value
	void setDecay(float newDecay) { decay = newDecay; };

	/// \brief return decay of object's bounce
	float getDecay() { return decay; };

	/// \brief Get the 'Is touching square' flag
	bool getIsTouching() { return isTouching; };

	// \brief return reference to positionY so that it can be safely modified by the user in external code
	float& getPositionY() { return positionY; };

private:

	/// \brief Store the vertices of the Square
	std::vector<float> vertices;

	/// \brief Bounce decay
	float decay = 0;

	/// \brief Indicates the order to draw coordinates to create a square
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief Stores new Y position of square after velocity is applied
	float positionY = 0.0f;

	/// \brief Each Square has a mass given to it. This weight is used to work out it's falling velocity.
	float mass = 20.0f;

	/// \brief The force a square exerts
	float force = 0.0f;

	/// \brief Flag to show whether or not a square can apply force (Will be false after collision to prevent force being applied multiple times)
	bool applyForce = true;

	/// States whether or not square is falling
	bool fallingFlag = false;

	/// \brief If the square is grounded
	int numberOfTimesBounced = 0;

	/// \brief Object's Velocity
	float velocity = 0;

	/// \brief Is the Object touching the Rectangle?
	bool isTouching = false;
};