//#pragma once
//#ifndef LOADER
//#define LOADER
//#include <vector>
//#include <GL/glew.h>
//#include <memory>
//
//#include "RawModel.h"
//#include "Mesh.h"
//
//class Loader
//{
//private:
//	std::vector<unsigned int> vbos, vaos;
//	
//
//public:
//	int createVAO();
//	void storeDataInAttributeList(const std::vector<Vertex>& vertices);
//	void unbindVAO() const;
//	void bindIndicesBuffer(const std::vector<unsigned int>& indices);
//	void cleanUp();
//	std::shared_ptr<RawModel> loadToVAO(const std::vector<Vertex>& positions, const std::vector<unsigned int>& indices);
//
//
//};
//
//#endif

#pragma once

//STD Libs
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

//GLEW

//GLFW

//OpenGL Math libs
#include<glm.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include "Model.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec2 texCoord;
	glm::vec3 normal;

	
};

std::ostream& operator<<(std::ostream& os, const glm::vec3& vertex)
{
	os << vertex.x << " " << vertex.y << " " << vertex.z;
	return os;
}

std::ostream& operator<<(std::ostream& os, const glm::vec2& vertex)
{
	os << vertex.x << " " << vertex.y;
	return os;
}


std::ostream& operator<<(std::ostream& os, const Vertex& vertex)
{
	os << vertex.position << " " << vertex.normal << " " << vertex.texCoord;
	return os;
}



static void loadOBJ(const char* file_name, std::vector<float>& result)
{
	//Vertex portions
	std::vector<glm::fvec3> vertex_positions;
	std::vector<glm::fvec2> vertex_texcoords;
	std::vector<glm::fvec3> vertex_normals;

	//Face vectors
	std::vector<int> vertex_position_indicies;
	std::vector<int> vertex_texcoord_indicies;
	std::vector<int> vertex_normal_indicies;

	//Vertex array
	std::vector<Vertex> vertices;

	std::stringstream ss;
	std::ifstream in_file(file_name);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_glint = 0;

	//File open error check
	if (!in_file.is_open())
	{
		throw "ERROR::OBJLOADER::Could not open file.";
	}

	//Read one line at a time
	while (std::getline(in_file, line))
	{
		
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "#")
		{

		}
		else if (prefix == "o")
		{

		}
		else if (prefix == "s")
		{

		}
		else if (prefix == "use_mtl")
		{

		}
		else if (prefix == "v") //Vertex position
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_positions.push_back(temp_vec3);
		}
		else if (prefix == "vt")
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoords.push_back(temp_vec2);
		}
		else if (prefix == "vn")
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normals.push_back(temp_vec3);
		}
		else if (prefix == "f")
		{
			int counter = 0;
			while (ss >> temp_glint)
			{
				//Pushing indices into correct arrays
				if (counter == 0)
					vertex_position_indicies.push_back(temp_glint);
				else if (counter == 1)
					vertex_texcoord_indicies.push_back(temp_glint);
				else if (counter == 2)
					vertex_normal_indicies.push_back(temp_glint);

				//Handling characters
				if (ss.peek() == '/')
				{
					++counter;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					++counter;
					ss.ignore(1, ' ');
				}

				//Reset the counter
				if (counter > 2)
					counter = 0;
			}
		}
		else
		{

		}
	}

	//Build final vertex array (mesh)
	vertices.resize(vertex_position_indicies.size(), Vertex());

	//Load in all indices
	for (size_t i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = vertex_positions[vertex_position_indicies[i] - 1];
		vertices[i].texCoord = vertex_texcoords[vertex_texcoord_indicies[i] - 1];
		vertices[i].normal = vertex_normals[vertex_normal_indicies[i] - 1];
	}

	for (size_t i = 0; i < vertices.size(); i++)
	{
		result.push_back(vertices[i].position.x);
		result.push_back(vertices[i].position.y);
		result.push_back(vertices[i].position.z);
		result.push_back(vertices[i].normal.x);
		result.push_back(vertices[i].normal.y);
		result.push_back(vertices[i].normal.z);
		result.push_back(vertices[i].texCoord.x);
		result.push_back(vertices[i].texCoord.y);

	}

	//DEBUG
	std::cout << "Nr of vertices: " << result.size() << "\n";

	//Loaded success
	std::cout << "OBJ file loaded!" << "\n";
}

