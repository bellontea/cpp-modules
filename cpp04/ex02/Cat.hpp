#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* _brain;

public:
	Cat();
	Cat(const Cat &obj);
	~Cat();

	Cat& operator=(const Cat &obj);

	void makeSound() const;
	Brain* getBrain() const;
};

