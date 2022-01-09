#pragma once
#ifndef MODEL
#define MODEL

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Light.h"

class RawModel
{
protected:
	VertexArray _va;
public:
	RawModel(const VertexArray& va) : _va(va) {};
	virtual void bind() const;
	virtual void unbind() const;
	virtual unsigned int getVertexCount() const;
};

class Model : public RawModel
{
private:
	Material _material;
public:
	Model(const VertexArray& va, const Material& material) : RawModel(va), _material(material) {};
	Model(const VertexArray& va) : RawModel(va) {};
	Material getMaterial() const;
	void bind() const override;
	void unbind() const override;
};

class IndexedModel : public RawModel
{
private:
	IndexBuffer _ib;
	Material _material;
public:
	IndexedModel(const VertexArray& vertexArr, const IndexBuffer& indexBuff,  const Material& material) : _ib(indexBuff), _material(material), RawModel(vertexArr) { };
	Material getMaterial() const;
	unsigned int getVertexCount() const;
};

#endif
