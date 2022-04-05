#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractional_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &object);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(const Fixed &object);
};

