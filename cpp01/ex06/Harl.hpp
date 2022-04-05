#include <iostream>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void default_answer( void );

public:
	Harl();
	~Harl();
	void complain( std::string level );
};

