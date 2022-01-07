#include "Shader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
{
	_vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
	_fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
	_programID = glCreateProgram();
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);
	bindAttributes();
	glLinkProgram(_programID);
	glValidateProgram(_programID);
	getAllUniformLocations();
}

Shader::~Shader()
{
	stop();
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
	glDeleteProgram(_programID);
}

void Shader::start() const
{
	glUseProgram(_programID);
}

void Shader::stop() const
{
	glUseProgram(0);
}

void Shader::cleanUp() const
{
	stop();
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
	glDeleteProgram(_programID);
}

unsigned int Shader::getUniformLocation(const std::string& location)
{
	if (_locationCache.find(location) != _locationCache.end())
	{
		return _locationCache[location];
	}
	int loc = glGetUniformLocation(_programID, location.c_str());
	if (loc == -1)
	{
		std::cout << "Warning! uniform " << location << " doesn't exist!" << std::endl;
	}
	_locationCache[location] = loc;
	return loc;
}

void Shader::bindAttribute(int attribute, const char* variableName)
{
	glBindAttribLocation(_programID, attribute, variableName);
}

void Shader::loadFloat(int location, float value) const
{
	glUniform1f(location, value);
}

void Shader::loadInt(int location, int value) const
{
	glUniform1i(location, value);
}

void Shader::loadBoolean(int location, bool value) const
{
	float toLoad = 0;
	if (value) toLoad = 1;
	glUniform1f(location, value);
}

void Shader::loadMat4(int location, const glm::mat4& value) const
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

void Shader::loadVec3(int location, const glm::vec3& value) const
{
	glUniform3fv(location, 1, &value[0]);
}

int Shader::loadShader(const std::string& file, int type)
{
	std::cout << file << std::endl;
	std::string code;
	std::ifstream shaderFile;
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		shaderFile.open(file);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		code = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}
	const char* shaderCode = code.c_str();
	int shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &shaderCode, NULL);
	glCompileShader(shaderID);
	int success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[1024];
		glGetShaderInfoLog(shaderID, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		return -1;
	}

	return shaderID;
}
