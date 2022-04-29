#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &copy);

	~MutantStack();

	MutantStack& operator=(const MutantStack& copy);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::iterator const_iterator;
	typedef typename std::stack<T>::container_type::iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::iterator const_reverse_iterator;

	iterator begin();
	iterator end();

	const_iterator cbegin();
	const_iterator cend();

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator crbegin();
	const_reverse_iterator crend();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	operator=(copy);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy)
{
	(void)copy;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
	return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
	return this->c.cend();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
	return this->c.crbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
	return this->c.crend();
}