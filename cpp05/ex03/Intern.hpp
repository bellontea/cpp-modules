#pragma once

#include "Form.hpp"
#include <iostream>

class Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	~Intern();

	Intern& operator=(const Intern& copy);

	Form* makeForm(std::string name, std::string target);

	class FormNotExistException : public std::exception
	{
		virtual const char* what() const throw();
	};
};
