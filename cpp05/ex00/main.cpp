
  
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "Test1: ";
		Bureaucrat b1("Test1", 151);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Test2: ";
		Bureaucrat b1("Test2", 14);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test3: ";
		Bureaucrat b1("Test3", 150);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test4: ";
		Bureaucrat b1("Test4", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Test5: ";
		Bureaucrat b1("Test15", -151);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}