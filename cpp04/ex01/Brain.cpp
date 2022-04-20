#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	this->operator=(obj);
}

Brain& Brain::operator=(const Brain &obj)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	return *this;
}

void Brain::addIdea(std::string idea)
{
	int i = 0;
	while (!_ideas[i].empty() && i < 100)
		i++;
	_ideas[i % 100] = idea;
}

void Brain::printIdeas() const
{
	for (size_t i = 0; _ideas[i] != ""; i++)
		std::cout << _ideas[i] << std::endl;
}