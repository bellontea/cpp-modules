#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &obj) : AAnimal(obj)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	_brain = NULL;
	this->operator=(obj);
}

Cat& Cat::operator=(const Cat &obj)
{
	AAnimal::operator=(obj);
	if (_brain)
		delete _brain;
	_brain = new Brain(*obj._brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}