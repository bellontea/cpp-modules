#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor of Brain called" << std::endl;
	_number = 0;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	this->operator=(obj);
	std::cout << "Copy constructor of Brain called" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	_number = obj._number;
	return *this;
}

void Brain::addIdea(std::string idea)
{
	if (_number == 100)
		_number = 0;
	_ideas[_number] = idea;
	_number++;
}

void Brain::printIdeas() const
{
	for (size_t i = 0; _ideas[i] != ""; i++)
		std::cout << _ideas[i] << std::endl;
}