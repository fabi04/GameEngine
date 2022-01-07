#pragma once
#ifndef INDEXBUFFER
#define INDEXBUFFER

#include <gl/glew.h>

class IndexBuffer
{
private:
	unsigned int _rendererID;
	unsigned int _count;
public:
	IndexBuffer(const void* data, unsigned int count);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return _count; };
};

#endif