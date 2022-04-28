#pragma once

#include <algorithm>

template <typename T>
int easyFind(T container, int n)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end())
		throw std::runtime_error("Number is not found.");
	return *iter;
}