#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		int n = easyFind(vec, 7);
		std::cout << n << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		int n = easyFind(vec, -3);
		std::cout << n << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
};