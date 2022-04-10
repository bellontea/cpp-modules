#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "name";
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
	this->operator=(object);
	std::cout << "ClapTrap " << _name << "copied and created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " deleted!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &object)
{
	_name = object._name;
	_health = object._health;
	_energy = object._energy;
	_damage = object._damage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy > 0)
	{
		_energy--;
		std::cout << "ClapTrap " << _name
				<< " attacks " << target 
				<< ", causing "<< _damage  
				<< " points of damage! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	std::cout << "ClapTrap " << _name 
			<< " recieved " << amount
			<< " points of damage!" << std::endl
			<< "hit " << _health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		_energy--;
		_health += amount;
		std::cout << "ClapTrap " << _name
				<< " has repaired himself! " << _energy
				<< " energy points remains." << std::endl;
	}
	else
		std::cout << "Not enough energy points!" << std::endl;
}

void ClapTrap::set_damage(int damage)
{
	_damage = damage;
}

int ClapTrap::get_damage()
{
	return _damage;
}