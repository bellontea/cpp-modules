#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Default constructor of AAnimal called" << std::endl;
	type = "";
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor of AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "Copy constructor of AAnimal called" << std::endl;
	this->operator=(obj);
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
	type = obj.type;
	return *this;
}

std::string AAnimal::getType() const
{
	return type;
}