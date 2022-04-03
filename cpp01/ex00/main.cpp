#include "Zombie.hpp"

int main()
{
	Zombie *z_heap = newZombie("Pupa");
	Zombie z_stack("Biba");
	randomChump("Boba");

	z_heap->announce();
	z_stack.announce();
	delete z_heap;
}