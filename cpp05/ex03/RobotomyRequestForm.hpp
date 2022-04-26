#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

	void execution() const;
};

