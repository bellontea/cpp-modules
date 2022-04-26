#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_execute;
	static const int max_grade = 1;
	static const int min_grade = 150;

public:
	Form();
	Form(const std::string name, const int grade_sign, const int grade_execute);
	Form(const Form &copy);
	virtual ~Form();

	Form& operator=(const Form& copy);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class SignedException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class UnsignedException : public std::exception
	{
		virtual const char* what() const throw();
	};

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const & executor) const;
	virtual void execution() const = 0;
};

std::ostream &operator<<(std::ostream &stream, const Form& form);
