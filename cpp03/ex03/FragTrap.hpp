#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& object);
	~FragTrap();

	FragTrap& operator=(const FragTrap &object);

	void highFivesGuys(void);
};

