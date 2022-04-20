#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default constructor of WrongCat called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	this->operator=(obj);
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	WrongAnimal::operator=(obj);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong meow" << std::endl;
}