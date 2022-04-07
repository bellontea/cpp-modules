#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &obj);

	~Point();

	Point& operator=(const Point &obj);

	const Fixed& getX() const;
	const Fixed& getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream& operator<<(std::ostream& stream, const Point &obj);