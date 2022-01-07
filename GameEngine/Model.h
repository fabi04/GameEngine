#pragma once
#ifndef MODEL
#define MODEL

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Light.h"


class BaseModel
{
protected:
	VertexArray _va;
	Texture _texture;
	Material _material;
public:
	BaseModel(const VertexArray& va, const Texture& texture, const Material& material) : _va(va), _texture(texture), _material(material) {};
	void bind() const;
	void unbind() const;
	Material getMaterial() const;
	virtual unsigned int getVertexCount() const = 0;
};

class Model : public BaseModel
{
public:
	unsigned int getVertexCount() const override;
	Model(const VertexArray& va, const Texture& texture, const Material& material) : BaseModel(va, texture, material) {};
};

class IndexedModel : public BaseModel
{
private:
	IndexBuffer _ib;
public:
	IndexedModel(const VertexArray& vertexArr, const IndexBuffer& indexBuff, const Texture& texture, const Material& material) : _ib(indexBuff), BaseModel(vertexArr, texture, material) { };
	unsigned int getVertexCount() const override;
};

#endif
