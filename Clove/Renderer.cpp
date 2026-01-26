#include "Renderer.h"
#include "Rectangle.h"

void objectLinker(VAO& ArrayObject, VBO& BufferObject, EBO& ElementBufferObject)
{
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);
}

void renderer(GLFWwindow* window, VAO& ArrayObject, Shaders& shader)
{
	Rectangle rect; // Temporary, right now this is being created every frame but it doesnt matter right now
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shader.use();
	shader.setFloat("ourColour", 1.0f, 1.0f, 1.0f, 1.0f);
	ArrayObject.bindArray();

	rect.draw();
}