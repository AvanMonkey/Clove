#include "Rectangle.h"
#include <glad/glad.h>

void Rectangle::draw() {
	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}

void Rectangle::updatePosition()
{
    float netDisplacement = 0.0f;
    bool applyForce = false;
    for (Square* s : squaresTouching) {
        netDisplacement += s->getForce() / getSprintConstant();
    }

    for (int i = 1; i < vertices.size(); i += 3) {
        vertices[i] = originalCoordinates[i] + netDisplacement;
    }

    // Update GPU buffers (same as before)
    ArrayObject.bindArray();
    BufferObject.bindBuffer(GL_ARRAY_BUFFER);
    ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
    glEnableVertexAttribArray(0);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vertexLocation);
};