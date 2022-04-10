#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap	claptrap1("Pupa");
	// ClapTrap	claptrap2("Lupa");

	// claptrap1.set_damage(5);
	// claptrap1.attack("Lupa");
	// claptrap2.takeDamage(claptrap1.get_damage());

	// claptrap2.beRepaired(5);

	// for (size_t i = 0; i < 10; i++)
	// 	claptrap1.attack("void");
	
	// ScavTrap	scavtrap1("Biba");
	// ScavTrap	scavtrap2("Boba");

	// scavtrap1.attack("Boba");
	// scavtrap2.takeDamage(scavtrap1.get_damage());

	// scavtrap2.beRepaired(20);

	// scavtrap1.guardGate();

	// FragTrap fragtrap1("Dude");

	// fragtrap1.highFivesGuys();

	DiamondTrap	diamond1("Cool");

	diamond1.takeDamage(50);
	diamond1.beRepaired(20);

	DiamondTrap diamond2 = diamond1;
	DiamondTrap diamond3;

	diamond2.beRepaired(20);
	diamond1.attack("void");
	diamond1.whoAmI();
	diamond2.whoAmI();
	diamond3.whoAmI();

	return 0;
}