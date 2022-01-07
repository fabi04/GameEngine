#pragma once
#ifndef MESH
#define MESH
#include <vector>

#include <glm.hpp>

#include "RawModel.h"
#include "Loader.h";

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
private:
	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;
	RawModel _model;
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

	
};

#endif
