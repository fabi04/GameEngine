#pragma once
#ifndef LIGHT
#define LIGHT
#include <glm/glm/glm.hpp>
#include "Texture.h"

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
	float constant, linear, quadratic;

	PointLight(const glm::vec3 pos, const glm::vec3 ambient, const glm::vec3 diffuse, const glm::vec3 specular, float constant, float linear, float quadratic)
		: Light(pos), ambient(ambient), specular(specular), diffuse(diffuse), constant(constant), linear(linear), quadratic(quadratic) {};
};

struct DirLight
{
	glm::vec3 direction;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

};

struct Material
{
	Texture* diffuseMap;
	Texture* specularMap;
	float shininess = 16.0f;
};
#endif