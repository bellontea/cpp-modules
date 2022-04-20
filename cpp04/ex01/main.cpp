#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMALS_COUNT 10

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;

	Animal **arr = new Animal* [ANIMALS_COUNT];

	for (size_t i = 0; i < ANIMALS_COUNT; i++)
	{
		if (i % 2)
		{
			arr[i] = new Dog();
			static_cast<Dog *>(arr[i])->getBrain()->addIdea("I am Dog");
		}
		else
		{
			arr[i] = new Cat();
			static_cast<Cat *>(arr[i])->getBrain()->addIdea("I am Cat");
		}
	}
	
	for (size_t i = 0; i < ANIMALS_COUNT; i++)
	{
		if (i % 2)
			static_cast<Dog *>(arr[i])->getBrain()->printIdeas();
		else
			static_cast<Cat *>(arr[i])->getBrain()->printIdeas();
		delete arr[i];
	}
	delete [] arr;

	return 0;
}