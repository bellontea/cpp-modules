#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
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