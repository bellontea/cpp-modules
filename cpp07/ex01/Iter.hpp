
#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F &&f)
{
	if (!array)
		throw std::invalid_argument("Null pointer array.");
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
