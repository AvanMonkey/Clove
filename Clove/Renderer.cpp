#include "Renderer.h"

void calculateVelocity(Square* square, float deltaTime)
{
	square->setForce(GRAVITY * deltaTime * square->getMass()); // Force = Mass * Gravity

	float forceScaled = square->getForce() * 0.001; // THIS IS ONLY FOR THE GRAPHICAL SIDE OF THINGS. NOT USED FOR CALCULATIONS RELATED TO HOOKES LAW. THE REASON FOR THIS IS THAT USING THE REAL FORCE FOR VELOCITY MAKES BOXES TOO FAST WHEN BEING PLACED
	float newVelocity = square->getVelocity() + forceScaled * deltaTime;
	square->setVelocity(newVelocity);
	square->updateLocation();
}

bool isColliding(Rectangle& rect, Square* square)
{
	float sqrLeft = square->getVertices()[6];
	float sqrRight = square->getVertices()[0];
	float sqrTop = square->getVertices()[10];
	float sqrBottom = square->getVertices()[4];

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

void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);

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
				float overlap = square->getVertices()[4] - rect.getVertices()[7];

				for (int i = 1; i < square->getVertices().size(); i += 3) {
					square->getVertices()[i] -= overlap; // correct y-axis
				}
			}

			// Delete oldest object once we go over threshold
			if (ptr->squaresCreated.size() > MAX_AMOUNT_OF_OBJECTS)
			{
				Square* oldestSquare = ptr->squaresCreated[0];
				
				rect.eraseItemInSquaresTouching(square);
				delete oldestSquare;
				ptr->squaresCreated.erase(ptr->squaresCreated.begin());
			}
		}
	}
	else if (!ptr->squaresCreated.empty() && !drawSquare)
	{
		rect.clearSquaresTouching();
		for (Square* square : ptr->squaresCreated)
		{
			delete square; // Delete pointer objects and clear the array of null values so the screen is genuienly reset with no dangling pointers or memory leaks
			ptr->squaresCreated.clear();
		}
	}
	rect.updatePosition(deltaTime);
	rect.draw();
}
