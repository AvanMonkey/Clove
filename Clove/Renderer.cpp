#include "Renderer.h"

void calculateVelocity(Square* square, float deltaTime)
{
	float newVelocity = square->getVelocity() - SPEED * deltaTime;
	square->setVelocity(newVelocity);
	square->updateLocation();
}

void renderer(GLFWwindow* window, Rectangle& rect, InputPointers* ptr, float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rect.draw();

	// We cant make this false afterwards otherwise it would instantly be cleared next frame by glClear
	if (drawSquare)
	{
		for (auto square : ptr->squaresCreated)
		{
			calculateVelocity(square, deltaTime);
			square->draw();

			// Delete oldest object once we go over threshold
			if (ptr->squaresCreated.size() > MAX_AMOUNT_OF_OBJECTS)
			{
				Square* oldestSquare = ptr->squaresCreated[0];
				delete oldestSquare;
				ptr->squaresCreated.erase(ptr->squaresCreated.begin());
			}
		}
	}
	else if (!ptr->squaresCreated.empty() && !drawSquare)
	{
		for (auto square : ptr->squaresCreated)
		{
			delete square; // Delete pointer objects and clear the array of null values so the screen is genuienly reset with no dangling pointers or memory leaks
			ptr->squaresCreated.clear();
		}
	}
}