#include "Character.hpp"

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		materials[i] = NULL;
}

Character::Character(const Character& copy)
{
	operator=(copy);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if(materials[i])
			delete materials[i];
}

Character& Character::operator=(const Character& copy)
{
	name = copy.name;
	for (unsigned int i = 0; i < 4; i++)
		if(copy.materials[i])
			materials[i] = copy.materials[i]->clone();
	return *this;
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
		if (!materials[i])
		{
			materials[i] = materia;
			return;
		}
}

void Character::unequip(int idx)
{
	for(; idx < 3; idx++)
		materials[idx] = materials[idx + 1];
	materials[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx < 4 && materials[idx])	
		materials[idx]->use(target);
}