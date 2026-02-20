#include "Renderer.h"

void calculateVelocity(Square* square, float deltaTime)
{
	square->setForce(GRAVITY * deltaTime * square->getMass()); // Force = Mass * Gravity

	float forceScaled = square->getForce() * 0.00001; // Scaled force for calculating velocity (Without scaling, the velocity is too strong to be seen on screen)
	float newVelocity = square->getVelocity() - forceScaled;
	square->setVelocity(newVelocity);
	square->updateLocation();
}

bool isColliding(Rectangle& rect, Square* square)
{

	float sqrLeft = square->vertices[6];
	float sqrRight = square->vertices[0];
	float sqrTop = square->vertices[10];
	float sqrBottom = square->vertices[4];

	float rectLeft = rect.vertices[0];
	float rectRight = rect.vertices[3];
	float rectTop = rect.vertices[7];
	float rectBottom = rect.vertices[1];

	// Code adapted from Aristurtle Dev (2024) https://www.youtube.com/watch?v=UOfbGeq0ZkM
	
	// AABB Collision detection
	return sqrRight > rectLeft &&
		sqrLeft < rectRight &&
		sqrTop > rectBottom &&
		sqrBottom < rectTop;

	// End of adapted code
}

void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rect.draw();

	// We cant make this false afterwards otherwise it would instantly be cleared next frame by glClear
	if (drawSquare)
	{
		for (Square* square : ptr->squaresCreated)
		{
			calculateVelocity(square, deltaTime);
			square->draw();

			bool collided = isColliding(rect, square);
			square->setFallingFlag(!collided); // Square will always fall unless a collision happens

			// If square hits rectangle
			if (collided)
			{
				square->setIsTouching();

				// Make sure we only put square in array once
				if (square->getApplyForce())
				{
					bool squareFound = rect.findSquaresTouching(square);
					if (!squareFound)
					{
						rect.setSquaresTouching(square);
					}
				}
				
				rect.updatePosition();

				// Add bounce if bounce is not over 10, in which case ground the object
				if (square->getNumberOfTimesBounced() >= 10)
				{
					square->setVelocity(0.0f);
					square->setFallingFlag(false);
				}
				else
				{
					square->addBounce();
				}

				// Snap Boxes on top of rectangle (Penetration resolution)
				float overlap = square->vertices[4] - rect.vertices[7];

				for (int i = 1; i < square->vertices.size(); i += 3) {
					square->vertices[i] -= overlap; // correct y-axis
				}
			}

			// Delete oldest object once we go over threshold
			if (ptr->squaresCreated.size() > MAX_AMOUNT_OF_OBJECTS)
			{
				Square* oldestSquare = ptr->squaresCreated[0];
				
				rect.eraseItemInSquaresTouching(square);
				rect.updatePosition();
				delete oldestSquare;
				ptr->squaresCreated.erase(ptr->squaresCreated.begin());
			}
		}
	}
	else if (!ptr->squaresCreated.empty() && !drawSquare)
	{
		rect.clearSquaresTouching();
		rect.updatePosition();
		for (Square* square : ptr->squaresCreated)
		{
			delete square; // Delete pointer objects and clear the array of null values so the screen is genuienly reset with no dangling pointers or memory leaks
			ptr->squaresCreated.clear();
		}
	}
}
