#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include "limits"

class Span
{
private:
	std::multiset<int> _values;
	size_t _max_size;

public:
	Span();
	Span(unsigned int size);
	Span(const Span &copy);

	~Span();

	Span& operator=(const Span &copy);

	template <typename T>
	void addNumber(T iter_begin, T iter_end);
	void addNumber(int number);

	int shortestSpan();
	int longestSpan();
};

