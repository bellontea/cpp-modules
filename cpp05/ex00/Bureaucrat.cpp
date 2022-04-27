#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(min_grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(min_grade)
{
	if (grade > min_grade)
		throw GradeTooLowException();
	else if (grade < max_grade)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	_grade = copy._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return stream;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < max_grade)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decremendGrade()
{
	if (_grade + 1 > min_grade)
		throw GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}