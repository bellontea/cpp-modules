#include "Span.hpp"

Span::Span()
{
	_max_size = 0;
}

Span::Span(unsigned int size)
{
	_max_size = size;
}

Span::Span(const Span &copy)
{
	operator=(copy);
}

Span::~Span()
{
}

Span& Span::operator=(const Span &copy)
{
	_max_size = copy._max_size;
	_values = copy._values;
	return *this;
}

void Span::addNumber(int number)
{
	if (_values.size() == _max_size)
		throw std::length_error("Cannot add new element because container lenght already has max size.");
	_values.insert(number);
}

template <typename T>
void Span::addNumber(T iter_begin, T iter_end)
{
  while (iter_begin != iter_end)
  {
    this->addNumber(*iter_begin);
    iter_begin++;
  }
}

int Span::shortestSpan()
{
	if (_values.size() < 2)
		throw std::runtime_error("Cannot find shortest span because container size lower than 2.");
	
	int res = __INT32_MAX__;
	int temp = 0;
	std::multiset<int>::iterator iter = _values.begin();
	while (true)
	{
		temp = *iter;
		iter++;
		if (iter == _values.end() || res == 0)
			break;
		if (*iter - temp < res)
			res = *iter - temp;
	}

	return res;
}

int Span::longestSpan()
{
	if (_values.size() < 2)
		throw std::runtime_error("Cannot find longest span because container size lower than 2.");
	
	return (*_values.rbegin() - *_values.begin());
}
