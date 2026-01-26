#include "Shaders.h"
// Code adapted from LearnOpenGL (2026) https://learnopengl.com/Getting-started/Shaders
void Shaders::use()
{
	glUseProgram(shaderID);
}

void Shaders::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
}

void Shaders::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shaders::setFloat(const std::string& name, float r, float g, float b, float opacity) const
{
	glUniform4f(glGetUniformLocation(shaderID, name.c_str()), r, g, b, opacity);
}

void Shaders::errorCheck(std::string errormsg)
{
	/// Check if there are any rendering issues during early development
	int  success;
	char infoLog[512];
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		errormsg += infoLog;
		throw std::runtime_error(errormsg);
	}
}
// End of adapted code