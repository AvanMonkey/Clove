#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/// \brief Create Shader Program through reading Vertex and Fragment Shader path files
class Shaders
{
public:
	Shaders(const char* vertexPath, const char* fragmentPath)
	{
		// Code adapted from LearnOpenGL (2026) https://learnopengl.com/Getting-started/Shaders

		// Retrieve the GLSL code 
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// For if reading shaders fails
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		// Try and load the vertex/fragment shaders from path
		try
		{
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);

			std::stringstream vShaderStream, fShaderStream;
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();


			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		unsigned int vertex, fragment;

		// Create Vertex Shader 
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		this->errorCheck("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");

		// Create Fragment Shader 
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);

		this->errorCheck("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
		// Link these and create shader program
		shaderID = glCreateProgram();
		glAttachShader(shaderID, vertex);
		glAttachShader(shaderID, fragment);
		glLinkProgram(shaderID);

		this->errorCheck("ERROR::SHADER::PROGRAM::LINKING::FAILED\n");

		// Delete Redundancies
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	/// Allow for shaderID access should it be manually requested
	unsigned int getID() { return shaderID; };

	/// brief Use the Shader
	void use();

	/// \brief Shader's Boolean Uniform Setter
	void setBool(const std::string& name, bool value) const; // Const is used here so any member variables are immutable and can't be changed

	/// \brief Shader's Int Uniform Setter
	void setInt(const std::string& name, int value) const;

	/// \brief Shader's Float Uniform Setter (Usualy Colour)
	void setFloat(const std::string& name, float r, float g, float b, float opacity) const;

	// End of adapted code



	/// \brief Check for errors during shader compilation process
	void errorCheck(std::string errorMessage);

	~Shaders() = default;
private:
	/// \brief Shader's Unique ID
	unsigned int shaderID;	// Encapsulated to prevent any accidental changes
};

#endif