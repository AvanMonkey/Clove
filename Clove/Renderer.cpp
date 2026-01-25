#include "Renderer.h"

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
"	FragColor = vec4(1.0f, 0.0f, 0.4549f, 1.0f);\n"
"}\0";

float vertices[] =
{
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f
};

unsigned int indices[] =
{
	0, 1, 3,
	1, 2, 3
};

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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	ElementBufferObject.bindBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int vertexLocation = 0;
	unsigned int vertexSize = 3;
	unsigned int stride = 3; // The space  between consectuive vertex attributes
	glVertexAttribPointer(vertexLocation, vertexSize, GL_FLOAT, GL_FALSE, stride * sizeof(float), byteOffset);
	glEnableVertexAttribArray(0);
}

void renderer(GLFWwindow* window, VAO& ArrayObject)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	ArrayObject.bindArray();

	unsigned int numberOfVertices = 6; 
	glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, byteOffset);
}