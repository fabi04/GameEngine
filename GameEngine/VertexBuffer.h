#pragma once
#ifndef VERTEXBUFFER
#define VERTEXBUFFER

#include <gl/glew.h>

class VertexBuffer
{
private:
	unsigned int _rendererID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};

#endif