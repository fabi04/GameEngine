#include "Model.h"

void BaseModel::bind() const
{
	_va.bind();
	_texture.bind();
}

void BaseModel::unbind() const
{
	_va.unbind();
	_texture.unbind();
}

Material BaseModel::getMaterial() const
{
	return _material;
}

unsigned int Model::getVertexCount() const
{
	return _va.getVertexCount();
}

unsigned int IndexedModel::getVertexCount() const
{
	return _ib.getCount();
}