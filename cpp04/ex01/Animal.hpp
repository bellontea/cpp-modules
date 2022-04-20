#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();

	Animal& operator=(const Animal &obj);

	std::string getType() const;
	virtual void makeSound() const;
};

