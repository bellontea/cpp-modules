#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	const Weapon &_weapon;

public:
	HumanA(std::string name, const Weapon &weapon);
	~HumanA();
	void attack();
};
