#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	claptrap1("Pupa");
	ClapTrap	claptrap2("Lupa");

	claptrap1.set_damage(5);
	claptrap1.attack("Lupa");
	claptrap2.takeDamage(claptrap1.get_damage());

	claptrap2.beRepaired(5);

	for (size_t i = 0; i < 10; i++)
		claptrap1.attack("void");
	
	ScavTrap	scavtrap1("Biba");
	ScavTrap	scavtrap2("Boba");

	scavtrap1.attack("Boba");
	scavtrap2.takeDamage(scavtrap1.get_damage());

	scavtrap2.beRepaired(20);

	scavtrap1.guardGate();

	FragTrap fragtrap1("Dude");

	fragtrap1.highFivesGuys();

	return 0;
}