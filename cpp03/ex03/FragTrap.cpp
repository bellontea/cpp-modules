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
	_energy = 50;
	_damage = 20;
	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object)
{
	operator=(object);
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

void FragTrap::attack(const std::string& target)
{
	if (_energy > 0)
	{
		_energy--;
		std::cout << "FragTrap " << _name
				<< " attacks " << target 
				<< ", causing "<< _damage  
				<< " points of damage! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	std::cout << "FragTrap " << _name 
			<< " recieved " << amount
			<< " points of damage!" << std::endl
			<< "hit " << _health << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		_energy--;
		_health += amount;
		std::cout << "FragTrap " << _name
				<< " has repaired himself! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five!" << std::endl;
}