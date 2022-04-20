#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	std::cout << "Default constructor of WrongDog called" << std::endl;
	type = "WrongDog";
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor of WrongDog called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &obj) : WrongAnimal(obj)
{
	std::cout << "Copy constructor of WrongDog called" << std::endl;
	this->operator=(obj);
}

WrongDog& WrongDog::operator=(const WrongDog &obj)
{
	WrongAnimal::operator=(obj);
	return *this;
}

void WrongDog::makeSound() const
{
	std::cout << "Wrong woof" << std::endl;
}