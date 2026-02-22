#include "Rectangle.h"
#include <glad/glad.h>
#include "Rectangle.h"
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

    printf("%f Force on Rectangle\n", netForce);

    float acceleration = netForce / getMass(); // a = F/m

    updateVelocity(acceleration, deltaTime); // v = a * t

    updateDisplacement(velocity, deltaTime);

    for (int i = 1; i < vertices.size(); i += 3) {
        verticesOfObject[i] = getOriginalCoordinates()[i] - x;
    }

    // Update GPU buffers (same as before)
    ArrayObject.bindArray();
    BufferObject.bindBuffer(GL_ARRAY_BUFFER);
    ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(vertexLocation);
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