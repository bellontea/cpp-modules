#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void) copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void) copy;
	return *this;
}

const char* Intern::FormNotExistException::what() const throw()
{
	return "Form name is incorrect.";
}

Form* createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form* createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form* createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string form_names[3] = {"PresidentialPardonForm", 
								"RobotomyRequestForm",
								"ShrubberyCreationForm"};

	Form *(*forms_create[3]) (std::string) = {
		createPresidentialPardonForm,
		createRobotomyRequestForm,
		createShrubberyCreationForm
	};
	
	for (size_t i = 0; i < 3; i++)
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms_create[i](target);
		}

	throw FormNotExistException();
	return NULL;	
}