//#include "Loader.h"
//
//#include <iostream>
//
//
//
//int Loader::createVAO()
//{
//	unsigned int vao;
//	glGenVertexArrays(1, &vao);
//	vaos.push_back(vao);
//	glBindVertexArray(vao);
//	return vao;
//}
//
//void Loader::storeDataInAttributeList(const std::vector<Vertex>& vertices)
//{
//	unsigned int vbo;
//	glGenBuffers(1, &vbo);
//	vbos.push_back(vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//}
//
//void Loader::unbindVAO() const
//{
//	glBindVertexArray(0);
//}
//
//void Loader::bindIndicesBuffer(const std::vector<unsigned int>& indices)
//{
//	unsigned int ebo;
//	glGenBuffers(1, &ebo);
//	vbos.push_back(ebo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
//
//}
//
//void Loader::cleanUp()
//{
//	for (unsigned int vao : vaos)
//	{
//		glDeleteVertexArrays(1, &vao);
//	}
//	for (unsigned int vbo : vbos)
//	{
//		glDeleteBuffers(1, &vbo);
//	}
//}
//
//std::shared_ptr<RawModel> Loader::loadToVAO(const std::vector<Vertex>& positions, const std::vector<unsigned int>& indices)
//{
//	unsigned int vao = createVAO();
//	storeDataInAttributeList(positions);
//	bindIndicesBuffer(indices);
//	std::shared_ptr<RawModel> model = std::make_shared<RawModel>(vao, 12);
//	return model;
//}
