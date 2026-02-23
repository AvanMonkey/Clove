#include "Renderer.h"

void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// We cant make this false afterwards otherwise it would instantly be cleared next frame by glClear
	if (drawSquare)
	{
		for (Square* square : ptr->squaresCreated)
		{
			square->calculateVelocity(deltaTime);
			square->draw();

			bool collided = square->isColliding(rect);
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
