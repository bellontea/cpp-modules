#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
//	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

Fixed::Fixed()
{
//	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &object)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->operator=(object);
}

Fixed::Fixed(const int value)
{
//	std::cout << "Int constructor called" << std::endl;
	_value = (value << _fractional_bits);
}

Fixed::Fixed(const float value)
{
//	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &object)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	_value = object.getRawBits();
	return *this;
}

float Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _fractional_bits);
}

int Fixed::toInt( void ) const
{
	return (_value >> _fractional_bits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& object)
{
	stream << object.toFloat();
	return stream;
}

bool Fixed::operator>(const Fixed &object) const
{
	return _value > object._value;
}

bool Fixed::operator<(const Fixed &object) const
{
	return _value < object._value;
}

bool Fixed::operator>=(const Fixed &object) const
{
	return _value >= object._value;
}

bool Fixed::operator<=(const Fixed &object) const
{
	return _value <= object._value;
}

bool Fixed::operator==(const Fixed &object) const
{
	return _value == object._value;
}

bool Fixed::operator!=(const Fixed &object) const
{
	return _value != object._value;
}

Fixed Fixed::operator+(const Fixed &object) const
{
	Fixed result(*this);
	result._value += object._value;

	return result;
}

Fixed Fixed::operator-(const Fixed &object) const
{
	Fixed result(*this);
	result._value -= object._value;
	
	return result;
}

Fixed Fixed::operator*(const Fixed &object) const
{
	Fixed result(*this);

	result._value *= object._value;
	result._value >>= _fractional_bits;
	return result;
}

Fixed Fixed::operator/(const Fixed &object) const
{
	Fixed result(*this);
	result._value /= object._value;
	result._value <<= _fractional_bits;
	
	return result;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed prev = *this;
	_value--;
	return prev;
}

Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed prev = *this;
	_value++;
	return prev;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2) ? obj1 : obj2;
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 < obj2) ? obj1 : obj2;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2) ? obj1 : obj2;
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2) ? obj1 : obj2;
}