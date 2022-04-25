 #pragma once

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string		name;
	AMateria		*materials[4];

public:
	Character();
	Character(std::string name);
	Character(const Character& copy);
	~Character();

	Character& operator=(const Character& copy);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};