#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	Animal::operator=(obj);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}