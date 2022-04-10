#pragma once

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _health;
	int _energy;
	int _damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& object);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &object);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void set_damage(int damage);
	int get_damage();
};

