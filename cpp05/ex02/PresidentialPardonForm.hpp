#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class PresidentialPardonForm : public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

	void execution() const;
};

