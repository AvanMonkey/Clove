#include "Square.h"
#include <glad/glad.h>
#include <iostream>
#include "Rectangle.h"

void Square::draw() {

	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Square::calculateVelocity(float deltaTime)
{
	setForce(GRAVITY * deltaTime * getMass()); // Force = Mass * Gravity

	float forceScaled = getForce() * 0.001; // THIS IS ONLY FOR THE GRAPHICAL SIDE OF THINGS. NOT USED FOR CALCULATIONS RELATED TO HOOKES LAW. THE REASON FOR THIS IS THAT USING THE REAL FORCE FOR VELOCITY MAKES BOXES TOO FAST WHEN BEING PLACED
	float newVelocity = getVelocity() + forceScaled * deltaTime;
	setVelocity(newVelocity);
	updateLocation();
}

bool Square::isColliding(Rectangle& rect)
{
	float sqrLeft = getVertices()[6];
	float sqrRight = getVertices()[0];
	float sqrTop = getVertices()[10];
	float sqrBottom = getVertices()[4];

	float rectLeft = rect.getVertices()[0];
	float rectRight = rect.getVertices()[3];
	float rectTop = rect.getVertices()[7];
	float rectBottom = rect.getVertices()[1];

	// Code adapted from Aristurtle Dev (2024) https://www.youtube.com/watch?v=UOfbGeq0ZkM

		// AABB Collision detection
	return sqrRight > rectLeft &&
		sqrLeft < rectRight &&
		sqrTop > rectBottom &&
		sqrBottom < rectTop;

	// End of adapted code
}

void Square::updateLocation()
{
	float& posY = getPositionY();
	std::vector<float>& verticesOfObject = getVertices();

	// Falling
	if (getFallingFlag())
	{
		posY += getVelocity();
	}
	// Bouncing (as objects will bounce when they hit a surface like in real life)
	else
	{
		posY *= getDecay();
		incrementNumberOfTimesBounced(); // This is so after the ball bounces 12 times, it comes to a stop, otherwise it would just vibrate (I genuienly can't work out a way to make this smooth so i'm doing it like this)
	}

	// Apply gravity to squares through changing the y axis of each vertices by velocity
	for (int i = 1; i < vertices.size(); i += 3)
	{
		verticesOfObject[i] -= posY;
	}

	// Code adapted from LearnOpenGL (2026)
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);

	// Load Vertices into GPU
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_DYNAMIC_DRAW);

	// Settings of what the shape being drawn will look like, it's position, etc.
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

	// Load Indices of which Vertices to use into GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	// Enable Settings
	glEnableVertexAttribArray(vertexLocation);
	// End of adapted code
}