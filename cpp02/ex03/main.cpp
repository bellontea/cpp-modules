#include "Point.hpp"

static	void displayAnswer(const Point& a, const Point& b, const Point& c, const Point& p)
{
	bool	res = bsp(a, b, c, p);
	
	if (res == true)
		std::cout << "Point " << p << " in triangle ";
	else
		std::cout << "Point " << p << " is NOT in triangle ";
	std::cout << a << ", " << b << ", " << c << std::endl;
}

int main()
{
	Point	a(0.0f, 0.0f), b(5.0f, 0.0f), c(0.0f, 5.0f);
	Point	point1(1.0f, 0.5f);
	Point	point2(10, 10);


	displayAnswer(a, b, c, point1);
	displayAnswer(a, b, c, point2);
	return 0;
}