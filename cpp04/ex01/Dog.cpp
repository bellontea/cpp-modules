#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	_brain = NULL;
	this->operator=(obj);
}

Dog& Dog::operator=(const Dog &obj)
{
	Animal::operator=(obj);
	if (_brain)
		delete _brain;
	_brain = new Brain(*obj._brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}