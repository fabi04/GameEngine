#include "Model.h"

void BaseModel::bind() const
{
	_material.diffuseMap->bind();
	_material.specularMap->bind(1);
	_va.bind();

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