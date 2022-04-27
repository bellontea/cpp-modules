
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat man("man", 1);
	Form* rrf = NULL;
	try
	{
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		man.signForm(*rrf);
		man.executeForm(*rrf);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(rrf)
		delete rrf;
}