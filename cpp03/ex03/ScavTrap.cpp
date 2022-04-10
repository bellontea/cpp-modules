#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& object) : ClapTrap(object)
{
	operator=(object);
	std::cout << "ScavTrap " << _name << "copied and created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " deleted!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &object)
{
	ClapTrap::operator=(object);
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energy > 0)
	{
		_energy--;
		std::cout << "ScavTrap " << _name
				<< " attacks " << target 
				<< ", causing "<< _damage  
				<< " points of damage! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	std::cout << "ScavTrap " << _name 
			<< " recieved " << amount
			<< " points of damage!" << std::endl
			<< "hit " << _health << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		_energy--;
		_health += amount;
		std::cout << "ScavTrap " << _name
				<< " has repaired himself! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}