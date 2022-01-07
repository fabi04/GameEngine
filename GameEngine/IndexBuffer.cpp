#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count) : _count(count)
{
	glGenBuffers(1, &_rendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_rendererID);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
}

void IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
