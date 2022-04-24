#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("dude", 150);

		Form form1("file1", 150, 110);
		std::cout << form1 << std::endl;
		b.signForm(form1);
		b.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat b("dude", 150);

		Form form1("file1", -10, 110);
		std::cout << form1 << std::endl;
		b.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}