#pragma once
#include <glad/glad.h>
#include <iostream>

/// \brief Create Shaders for use in rendering
class Shader
{
public:
	Shader(const char* ShaderSource, GLenum shaderType) {
		shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &ShaderSource, NULL);
		glCompileShader(shader);
	};
	~Shader() = default; 

	unsigned int getID() { return shader; };

	void errorCheck()
	{
		/// Check if there are any rendering issues during early development
		int  success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::string errormsg = "ERROR::SHADER::COMPILATION_FAILED\n";
			errormsg += infoLog;
			throw std::runtime_error(errormsg);
		}
	}
private:
	unsigned int shader;
};
