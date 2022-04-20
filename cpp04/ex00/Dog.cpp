#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	this->operator=(obj);
}

Dog& Dog::operator=(const Dog &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}