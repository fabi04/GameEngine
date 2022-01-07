
#include "Data.h"

Data::Data(const float* data, const int size) : _data(data), _size(size) {}

const int Data::getSize() const
{
	return _size;
}

const float* Data::getData() const
{
	return _data;
}


