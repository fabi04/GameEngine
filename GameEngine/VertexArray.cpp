#include "VertexArray.h"

VertexArray::VertexArray(unsigned int count) : _count(count)
{
	glGenVertexArrays(1, &_rendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_rendererID);
}



void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.size, element.type, element.normalized, layout.getStride(),(const void*) offset );
		offset += element.size * VertexBufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(_rendererID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

unsigned int VertexArray::getVertexCount() const
{
	return _count;
}
