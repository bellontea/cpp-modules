#include "ClapTrap.hpp"

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
	
	return 0;
}