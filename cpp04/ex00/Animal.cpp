#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor of Animal called" << std::endl;
	type = "";
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
	this->operator=(obj);
}

Animal& Animal::operator=(const Animal &obj)
{
	type = obj.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "*random animal noizes*" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}