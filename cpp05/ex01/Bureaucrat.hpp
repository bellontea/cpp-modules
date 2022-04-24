#pragma once

#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	static const int max_grade = 1;
	static const int min_grade = 150;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& copy);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decremendGrade();

	void signForm(Form& form) const;
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat& obj);
