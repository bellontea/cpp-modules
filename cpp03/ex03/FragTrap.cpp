#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object)
{
	std::cout << "FragTrap " << _name << "copied and created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " deleted!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &object)
{
	ClapTrap::operator=(object);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five!" << std::endl;
}