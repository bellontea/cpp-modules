#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
	type = "";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	this->operator=(obj);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*random WrongAnimal noizes*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}