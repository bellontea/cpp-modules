#include "Harl.hpp"

Harl::Harl()
{
	
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn't put enough bacon in my burger!"
				<< "If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
				<< "I've been coming for years whereas you started "
				<< "working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::default_answer( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain( std::string level )
{
	const std::string names[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	int i = 0;
	
	for (; !names[i].empty(); i++)
	{
		if (!level.compare(names[i]))
			break;
	}

	switch (i)
	{
		case 0: debug();
		case 1: info();
		case 2: warning();
		case 3: error(); break;
		default: default_answer(); break;
	}
}