#pragma once
class Data
{
private:
	const float* _data;
	const int _size;
public:
	Data(const float* data, const int size);

	const int getSize() const;
	const float* getData() const;
};

