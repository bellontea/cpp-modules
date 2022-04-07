#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &obj) : _x(obj._x), _y(obj._y)
{
}

Point& Point::operator=(const Point &obj)
{
	(void)obj;
	(Fixed)_x = obj._x;
	(Fixed)_y = obj._y;
	return *this;
}

const Fixed& Point::getX() const
{
	return _x;
}

const Fixed& Point::getY() const
{
	return _y;
}

std::ostream& operator<<(std::ostream& stream, const Point& obj)
{
	stream << "(" << obj.getX() << "; " << obj.getY() << ")";
	return stream;
}