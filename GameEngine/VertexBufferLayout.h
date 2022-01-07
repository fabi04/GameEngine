#pragma once
#include <vector>
#include <GL/glew.h>


struct VertexBufferElement
{
	unsigned int type;
	unsigned int size;
	unsigned char normalized;

	static unsigned int getSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
		}
		return 0;
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> _elements;
	unsigned int _stride;
public:
	VertexBufferLayout() : _stride(0) {};

	template <typename T>
	void push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void push<float>(unsigned int count)
	{
		VertexBufferElement element{ GL_FLOAT, count, GL_FALSE };
		_elements.push_back(element);
		_stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void push<unsigned int>(unsigned int count)
	{
		VertexBufferElement element{ GL_UNSIGNED_INT, count, GL_FALSE };
		_elements.push_back(element);
		_stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;

	}

	inline const std::vector<VertexBufferElement> getElements() const { return _elements; };
	inline unsigned int getStride() const { return _stride; };
};