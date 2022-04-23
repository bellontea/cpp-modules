#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* _brain;

public:
	Dog();
	Dog(const Dog &obj);
	~Dog();

	Dog& operator=(const Dog &obj);

	void makeSound() const;
	Brain* getBrain() const;
};

