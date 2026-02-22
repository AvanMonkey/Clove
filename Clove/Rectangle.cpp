#include "Rectangle.h"
#include <glad/glad.h>

void Rectangle::draw() {
	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Rectangle::updatePosition(float deltaTime)
{

    deltaTime = deltaTime / CLOCKS_PER_SEC * 100;
    float netForce = 0.0f;
    float decay = 0.5;
    float decayValue = -decay * velocity;
    for (Square* s : squaresTouching) {
        netForce += s->getForce();
    }

    float springForce = x * -getSprintConstant(); // Hooke's Law

    netForce = netForce + springForce + decayValue;

    float acceleration = netForce / mass; // a = F/m

    velocity = acceleration * deltaTime; // v = a * t
    x += velocity * deltaTime;


    for (int i = 1; i < vertices.size(); i += 3) {
        vertices[i] = originalCoordinates[i] + x;
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
    auto it = std::find(squaresTouching.begin(), squaresTouching.end(), square);
    if (it != squaresTouching.end())
    {
        squaresTouching.erase(it);
    }
}