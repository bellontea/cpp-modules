#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	_name = "";
	_health = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	_name = name;
	_health = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap " << _name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) : ClapTrap(object), ScavTrap(object), FragTrap(object)
{
	_name = object._name;
	std::cout << "DiamondTrap " << _name << " copied and created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " deleted!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &object)
{
	ClapTrap::operator=(object);
	_name = object._name;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "\nMy name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << "\n" << std::endl;
}