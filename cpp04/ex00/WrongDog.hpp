#pragma once

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog();
	WrongDog(const WrongDog &obj);
	~WrongDog();

	WrongDog& operator=(const WrongDog &obj);

	void makeSound() const;
};

