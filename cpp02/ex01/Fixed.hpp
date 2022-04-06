#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fractional_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &object);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed& operator=(const Fixed &object);
	
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& object);
