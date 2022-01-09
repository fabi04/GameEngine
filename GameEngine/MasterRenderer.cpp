#include "MasterRenderer.h"
#include <GL/glew.h>
#include <iostream>

MasterRenderer* MasterRenderer::getInstance(StaticShader* shader)
{
	static MasterRenderer instance(shader);
	return &instance;
}

MasterRenderer::MasterRenderer(StaticShader* shader) : _shader(shader)
{
}

void MasterRenderer::prepare() const
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void MasterRenderer::cleanUp() const
{
	_shader->cleanUp();
}

template <>
void MasterRenderer::add<PointLight>(const PointLight& instance)
{
	_lights.push_back(instance);
}

template <>
void MasterRenderer::add<DirLight>(const DirLight& instance)
{
	_dirLights.push_back(instance);
}

template <>
void MasterRenderer::add<Model>(const Model& model)
{
	_models.push_back(model);
}

void MasterRenderer::prepareInstance(const Model& model) 
{
	_shader->loadFloat(_shader->getUniformLocation("tex"), 0);
}

void MasterRenderer::prepareRender() const
{
	_shader->start();
	_shader->loadPointLights(_lights);
	_shader->loadDirLights(_dirLights);
}

void MasterRenderer::render(const Model& model)
{
	_shader->start();
	_shader->loadMaterial(model);
	prepare();	
	model.bind();
	glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
}

//void MasterRenderer::render(const IndexedModel& model)
//{
//	_shader->start();
//
//	_shader->loadMaterial(model.getMaterial());
//	prepare();
//	model.bind();
//	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
//}

