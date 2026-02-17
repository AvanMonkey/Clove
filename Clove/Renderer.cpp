#include "Renderer.h"

void calculateVelocity(Square* square, float deltaTime)
{
	float newVelocity = square->getVelocity() - GRAVITY * deltaTime;
	square->setVelocity(newVelocity);
	square->updateLocation(deltaTime);
}

bool isColliding(Rectangle& rect, Square* sqr)
{

	float sqrLeft = sqr->vertices[6];
	float sqrRight = sqr->vertices[0];
	float sqrTop = sqr->vertices[10];
	float sqrBottom = sqr->vertices[4];

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
		for (auto square : ptr->squaresCreated)
		{
			bool collided = isColliding(rect, square);

			calculateVelocity(square, deltaTime);
			square->draw();

			if (collided)
			{
				printf("Collision \n");
				square->stopVelocity(); // stop falling

				// Snap Boxes on top of rectangle
				float overlap = square->vertices[4] - rect.vertices[7];
				for (int i = 1; i < square->vertices.size(); i += 3) {
					square->vertices[i] -= overlap; // correct y-axis
				}
			}

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