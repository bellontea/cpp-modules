#include "Form.hpp"

Form::Form() : _name("none"), _signed(0), _grade_sign(min_grade), _grade_execute(min_grade)
{
}

Form::~Form()
{
}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : _name(name), _signed(0), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (_grade_sign > min_grade || _grade_execute > min_grade)
		throw GradeTooLowException();
	if (_grade_sign < max_grade || _grade_execute < max_grade)
		throw GradeTooHighException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), 
		_grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{
}

Form& Form::operator=(const Form& copy)
{
	_signed = copy._signed;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSignedStatus() const
{
	return _signed;
}

int Form::getGradeRequiredToSign() const
{
	return _grade_sign;
}

int Form::getGradeRequiredToExecute() const
{
	return _grade_execute;
}

std::ostream &operator<<(std::ostream &stream, const Form& form)
{
	stream << "{";
	stream << "Name : \"" << form.getName() << "\", ";
	stream << "Is Signed : \"" << (form.getSignedStatus() ? "Yes" : "No") << "\", ";
	stream << "Grade to sign : \"" << form.getGradeRequiredToSign() << "\", ";
	stream << "Grade to execute : \"" << form.getGradeRequiredToExecute() << "\" ";
	stream << "}";
	return stream;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char* Form::SignedException::what() const throw()
{
	return "Form is already signed.";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_sign)
	{
		throw Form::GradeTooLowException();
	}
	else if (_signed)
		throw Form::SignedException();
	else
		_signed = true;
}