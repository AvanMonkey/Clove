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

		std::vector<float> verticesCoordinates =
		{
		-0.2f, 0.5f, 0.0f,  // bottom-left
		 0.2f, 0.5f, 0.0f,  // bottom-right
		 0.2f, 0.7f, 0.0f,  // top-right
		-0.2f, 0.7f, 0.0f   // top-left
		};

		setVertices(verticesCoordinates);

		setOriginalCoordinates(getVertices()); // We could use verticesCoordinates, but this way we can ensure that we are genuienly making a copy of vertices

		ArrayObject.bindArray();
		BufferObject.bindBuffer(GL_ARRAY_BUFFER);
		ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glEnableVertexAttribArray(0);

		// Load Vertices into GPU
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);

		// Settings of what the shape being drawn will look like, it's position, etc.
		glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);

		// Load Indices of which Vertices to use into GPU
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		// Enable Settings
		glEnableVertexAttribArray(vertexLocation);

	};
	~Rectangle() = default;

	/// \brief Draw the Object on the screen
	void draw();

	/// \brief Update the object's position
	void updatePosition(float deltaTime);

	/// \brief Return reference to coordinates of object's vertices
	std::vector<float>& getVertices() { return vertices; };

	/// \brief Set object's vertices coordinates
	void setVertices(std::vector<float> newVertices) { vertices = newVertices; };

	/// \brief Return coordinates of original object location on initialisation
	std::vector<float> getOriginalCoordinates(){return originalCoordinates; };

	/// \brief Set original coordinates to be saved should the original vector be changed
	void setOriginalCoordinates(std::vector<float> newOriginalCoordinates) { originalCoordinates = newOriginalCoordinates; };

	/// \brief Work out the force being applied to the object
	float getSprintConstant() { return k; };

	/// \brief Set displacement
	void setDisplacement(float newX) { x = newX; };

	/// \brief Update displacement
	void updateDisplacement(float value, float deltaTime) { x += value * deltaTime; };

	/// \brief Return flag stating whether or not squares have  been cleared
	bool getClearSquaresFlag() { return clearSquares; };

	/// \brief Return flag stating whether or not squares have  been cleared
	void setClearSquaresFlag(bool value) { clearSquares = value; };

	/// \brief Return Reference to squares touching vector
	std::vector<Square*>& getSquaresTouching() { return squaresTouching; };

	/// \brief Add to Squares Touching Vector
	void setSquaresTouching(Square* square) { squaresTouching.push_back(square); };

	/// \brief Return the Velocity of the object
	float getVelocity() { return velocity; };

	/// \brief Set Velocity
	void setVelocity(float newVelocity) { velocity = newVelocity; };

	/// \brief Update Velocity
	void updateVelocity(float value, float deltaTime) { velocity += value * deltaTime; };

	/// \brief Return the Mass of the object
	float getMass() { return mass; };

	/// \brief Return the oscillation decay of the object
	float getDecay() { return decay; };

	/// \brief Return true if square is found in 'squaresTouching'
	bool findSquaresTouching(Square* square);

	/// \brief Erase an item in 'squaresTouching'
	void eraseItemInSquaresTouching(Square* square);

	/// \brief Clear Squares Touching Vector
	void clearSquaresTouching() { squaresTouching.clear(); };

private:
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	/// \brief Store the vertices of the Rectangle
	std::vector<float> vertices;

	/// \brief Store original Top Left Coordinate's Y axis to work out displacement
	std::vector<float> originalCoordinates;

	/// \brief How stiff the rectangle is
	float k = 50.0f;

	/// \brief Displacement in length from extension
	float x = 0.0f;

	/// \brief Velocity of the Object
	float velocity = 0.0f;

	/// \breif Mass of the Object
	float mass = 1.0f;

	/// \brief Flag stating whether or not user has cleared all squares
	bool clearSquares = false;

	/// \brief Vector of all the squares touching the object.
	std::vector<Square*> squaresTouching;

	/// \brief Decay given to object oscillation
	float decay = 2.0;
};