#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice& copy)
{
	AMateria::operator=(copy);
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice;
}

