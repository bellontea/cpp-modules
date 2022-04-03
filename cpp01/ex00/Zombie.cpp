#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " died\n";
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
