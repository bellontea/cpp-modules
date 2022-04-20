#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal &obj);

	std::string getType() const;
	void makeSound() const;
};

