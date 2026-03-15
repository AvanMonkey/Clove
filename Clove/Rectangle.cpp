#include "Rectangle.h"
#include "Square.h"
#include <glad/glad.h>

void Rectangle::draw() {
	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Rectangle::updatePosition(float deltaTime)
{
    float netForce = 0.0f;
    float decayValue = -getDecay() * velocity; // Decay will be given to rectangle to stop oscillation
    std::vector<float>& verticesOfObject = getVertices();

    std::vector<Square*>& squaresTouchingRectangle = getSquaresTouching();

    for (Square* s : squaresTouchingRectangle) {
        netForce += s->getForce();
    }

    float springForce = x * -getSprintConstant(); // Hooke's Law

    netForce = netForce + springForce + decayValue;
    float acceleration = netForce / getMass(); // a = F/m
    float velocityIncrement = acceleration * deltaTime; // This is just here for testing to make sure out velocity calculation is accurate to the equation.
   
    updateVelocity(acceleration, deltaTime); // v = a * t
    updateDisplacement(velocity, deltaTime); // Displacement adds the velocity * deltaTime

    // Print for testing calculation accuracy

    printf("Velocity Equation Values\n\n");
    printf("%f Mass of the Platform\n\n", getMass());
    printf("%f Acceleration of the Platform\n\n", acceleration);
    printf("%f Delta Time\n\n", deltaTime);
    printf("%f Velocity increment of Platform\n\n\n", velocityIncrement);

    printf("Hooke's Law Equation Values\n\n");
    printf("%f Net Force on Platform\n\n", netForce);
    printf("%f Spring Constant of the Platform\n\n", getSprintConstant());
    printf("%f Displacement of the Platform\n\n\n\n\n", x);

    for (int i = 1; i < vertices.size(); i += 3) {
        verticesOfObject[i] = getOriginalCoordinates()[i] - x;
    }

    // Update GPU buffers (same as before)
    ArrayObject.bindArray();
    BufferObject.bindBuffer(GL_ARRAY_BUFFER);
    ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);

    // Code adapted from LearnOpenGL (2026)
    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(vertexLocation);
    // End of adapted code
};

bool Rectangle::findSquaresTouching(Square* square)
{
    std::vector<Square*>& squaresTouchingRectangle = getSquaresTouching();

    auto it = std::find(squaresTouchingRectangle.begin(), squaresTouchingRectangle.end(), square);
    if (it != squaresTouchingRectangle.end())
    {
        return true;
    }
    return false;
};

void Rectangle::eraseItemInSquaresTouching(Square* square) {

    std::vector<Square*>& squaresTouchingRectangle = getSquaresTouching();
    auto it = std::find(squaresTouchingRectangle.begin(), squaresTouchingRectangle.end(), square);
    if (it != squaresTouchingRectangle.end())
    {
        squaresTouchingRectangle.erase(it);
    }
}