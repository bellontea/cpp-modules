#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	Form::operator=(copy);
	_target = copy._target;
	return *this;
}

void RobotomyRequestForm::execution() const
{
	srand(time(NULL));
	if(rand() % 2)
		std::cout << "DRRR...RRR " + _target + " has been robotomized" << std::endl;
	else
		std::cout << "DRRR...RRR " + _target + " robotomized is failed" << std::endl;
}