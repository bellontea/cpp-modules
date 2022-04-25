#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	scavtrap1("Biba");
	ScavTrap	scavtrap2("Boba");

	scavtrap1.attack("Boba");
	scavtrap2.takeDamage(scavtrap1.get_damage());

	scavtrap2.beRepaired(20);

	scavtrap1.guardGate();

	return 0;
}