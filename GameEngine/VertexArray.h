#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <GL/glew.h>

class VertexArray
{
private:
	unsigned int _rendererID;
	unsigned int _count;
public:
	VertexArray(unsigned int count);
	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void bind() const;
	void unbind() const;
	unsigned int getVertexCount() const;
};

