#include "Renderer.h"
#include "Rectangle.h"

unsigned int shaderProgram;
const void* byteOffset = nullptr;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
"}\0";



void createShaders()
{
	Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER), fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	vertexShader.errorCheck();
	fragmentShader.errorCheck();

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader.getID());
	glAttachShader(shaderProgram, fragmentShader.getID());
	glLinkProgram(shaderProgram);
}

void objectLinker(VAO& ArrayObject, VBO& BufferObject, EBO& ElementBufferObject)
{
	ArrayObject.bindArray();
	BufferObject.bindBuffer(GL_ARRAY_BUFFER);
	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glEnableVertexAttribArray(0);
}

void renderer(GLFWwindow* window, VAO& ArrayObject)
{
	Rectangle rect;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	ArrayObject.bindArray();

	rect.draw();
}