#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	Form::operator=(copy);
	_target = copy._target;
	return *this;
}

void ShrubberyCreationForm::execution() const
{
	std::ofstream file;
	file.open((_target + "_srubber").c_str());
	file << 	"           * 				\n"
			<< 	"          /|\\      	    \n"       
			<< 	"         /*|O\\			\n"
			<< 	"        /*/|\\*\\			\n"
			<< 	"       /X/O|*\\X\\			\n"
			<< 	"      /*/X/|\\X\\*\\		\n"
			<< 	"     /O/*/X|*\\O\\X\\		\n"
			<< 	"    /*/O/X/|\\X\\O\\*\\	\n"
			<< 	"   /X/O/*/X|O\\X\\*\\O\\	\n"
			<< 	"  /O/X/*/O/|\\X\\*\\O\\X\\	\n"
			<< 	"          |X|				\n"
			<< 	"          |X|				\n"    
			<< std::endl;
	file.close();
}