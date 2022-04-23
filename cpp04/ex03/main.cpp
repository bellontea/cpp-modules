#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new  Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter* dude = new Character("dude");

	dude->equip(src->createMateria("ice"));
	dude->equip(src->createMateria("cure"));

	ICharacter* bob = new Character("bob");
	
	dude->use(0, *bob);
	dude->use(1, *bob);

	delete bob;
	delete dude;
	delete src;
	delete ice;
	delete cure;
	return 0;
}