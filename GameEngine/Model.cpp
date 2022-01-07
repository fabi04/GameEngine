#include "Model.h"

void BaseModel::bind() const
{
	_va.bind();
	_material.diffuseMap.bind();
	_material.specularMap.bind();

}

void BaseModel::unbind() const
{
	_va.unbind();
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