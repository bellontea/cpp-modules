#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& object);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap &object);

	void attack(const std::string& target);

	void whoAmI();
};
