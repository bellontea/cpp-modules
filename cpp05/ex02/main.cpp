
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm	form1("Tree");
		RobotomyRequestForm		form2("Robot");
		PresidentialPardonForm	form3("President");

		Bureaucrat				man1("John", 1);
		
		form1.beSigned(man1);
		man1.executeForm(form1);

		form2.beSigned(man1);
		man1.executeForm(form2);
		
		form3.beSigned(man1);
		man1.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}