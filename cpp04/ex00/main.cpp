#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_j = new WrongDog();
	const WrongAnimal* wrong_i = new WrongCat();
	const WrongCat* wrong_cat = new WrongCat();
	const WrongDog* wrong_dog = new WrongDog();

	wrong_i->makeSound();
	wrong_j->makeSound();
	wrong_meta->makeSound();
	wrong_cat->makeSound();
	wrong_dog->makeSound();

	delete wrong_meta;
	delete wrong_j;
	delete wrong_i;
	delete wrong_cat;
	delete wrong_dog;

	return 0;
}