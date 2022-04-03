#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie* horde;
	int N = 10;

	if (argc != 2)
		return (1);
	horde = zombieHorde(N, argv[1]);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;
}