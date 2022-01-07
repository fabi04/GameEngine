#pragma once
#ifndef LIGHT
#define LIGHT
#include <glm/glm/glm.hpp>

struct Light
{
	glm::vec3 pos;
	Light(const glm::vec3 pos) : pos(pos) {};
};

struct PointLight : Light
{
	glm::vec3 ambient;
	glm::vec3 specular;
	glm::vec3 diffuse;

	PointLight(const glm::vec3 pos, const glm::vec3 ambient, const glm::vec3 diffuse, const glm::vec3 specular)
		: Light(pos), ambient(ambient), specular(specular), diffuse(diffuse) {};
};

struct Material
{
	int texture;
	float shininess;
	glm::vec3 specular;
};
#endif