#pragma once
#ifndef SHADER
#define SHADER
#include <string>
#include <unordered_map>
#include <glm/glm/glm.hpp>

class Shader
{
private:
	int _programID;
	int _vertexShaderID;
	int _fragmentShaderID;
	std::unordered_map<std::string, unsigned int> _locationCache;

public:
	Shader(const std::string& vertextFile, const std::string& fragmentFile);
	~Shader();
	void start() const;
	void stop() const;
	void cleanUp() const;
	virtual void getAllUniformLocations() = 0 {};
	unsigned int getUniformLocation(const std::string& location);
	virtual void bindAttributes() = 0 {};
	void bindAttribute(int attribute, const char* variableName);
	void loadFloat(int location, float value) const;
	void loadInt(int location, int value) const;
	void loadBoolean(int location, bool value) const;
	void loadMat4(int location, const glm::mat4& value) const;
	void loadVec3(int location, const glm::vec3& value) const;
private:
	static int loadShader(const std::string& file, int type);
};

#endif

