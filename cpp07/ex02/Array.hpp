#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();

	Array& operator=(const Array& copy);
	T& operator[](int index);
	const T& operator[](int index) const;

	class IndexOutOfArrayException : public std::exception
	{
		virtual const char* what() const throw();
	};

	int size() const;
};

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = new T[_size];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	_array = NULL;
	operator=(copy);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (_array)
		delete[] _array;
	_size = copy._size;
	_array = new T[_size];
	for (int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
	
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index >= _size || index < 0)
		throw IndexOutOfArrayException();
	else
		return _array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index >= _size || index < 0)
		throw IndexOutOfArrayException();
	else
		return _array[index];
}

template <typename T>
int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfArrayException::what() const throw()
{
	return "Index out of array.";
}
