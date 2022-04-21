#pragma once

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
	int _number;

public:
	Brain();
	Brain(const Brain &obj);
	~Brain();

	Brain& operator=(const Brain &obj);
	void addIdea(std::string idea);
	void printIdeas() const;
};

