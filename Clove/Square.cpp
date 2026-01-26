#include "Square.h"
#include <glad/glad.h>

void Square::draw() {

	ArrayObject.bindArray();

	// Draw
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}