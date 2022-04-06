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

	bool operator>(const Fixed &object) const;
	bool operator<(const Fixed &object) const;
	bool operator>=(const Fixed &object) const;
	bool operator<=(const Fixed &object) const;
	bool operator==(const Fixed &object) const;
	bool operator!=(const Fixed &object) const;

	Fixed operator+(const Fixed &object) const;
	Fixed operator-(const Fixed &object) const;
	Fixed operator*(const Fixed &object) const;
	Fixed operator/(const Fixed &object) const;

	Fixed& operator--();
	Fixed operator--(int);
	Fixed& operator++();
	Fixed operator++(int);

	static Fixed& min(Fixed &obj1, Fixed &obj2);
	static const Fixed& min(const Fixed &obj1, const Fixed &obj2);
	static Fixed& max(Fixed &obj1, Fixed &obj2);
	static const Fixed& max(const Fixed &obj1, const Fixed &obj2);
	
};

std::ostream& operator<<(std::ostream& stream, const Fixed& object);
