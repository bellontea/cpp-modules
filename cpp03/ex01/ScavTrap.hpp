#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& object);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap &object);

	void guardGate();
	void attack(const std::string& target);
};
