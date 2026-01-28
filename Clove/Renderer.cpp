#include "Renderer.h"

void objectLinker(VAO& ArrayObject, VBO& BufferObject, EBO& ElementBufferObject)
{
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);
}

void renderer(GLFWwindow* window, Rectangle& rect)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rect.draw();

	// We cant make this false afterwards otherwise it would instantly be cleared next frame by glClear
	if (drawSquare)
	{
		Square sqr = Square(float(xpos), float(ypos));
		sqr.draw();
	}
}