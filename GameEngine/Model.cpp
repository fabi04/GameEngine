#include "Model.h"

void RawModel::bind() const
{
	_va.bind();

}

void RawModel::unbind() const
{
	_va.unbind();
}

unsigned int RawModel::getVertexCount() const
{
	return _va.getVertexCount();
}



void Model::bind() const
{
	_va.bind();
	_material.diffuseMap->bind();
	_material.specularMap->bind(1);
}

void Model::unbind() const
{
	_va.unbind();
	_material.diffuseMap->unbind();
	_material.specularMap->unbind();
}

Material Model::getMaterial() const
{
	return _material;
}

unsigned int IndexedModel::getVertexCount() const
{
	return _ib.getCount();
}
Material IndexedModel::getMaterial() const
{
	return _material;
}