#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	(std::string)_name = copy._name;
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

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " 
				<< form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign "
				<< form.getName() << " because " 
				<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " 
				<< form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot execute "
				<< form.getName() << " because " 
				<< e.what() << std::endl;
	}
}