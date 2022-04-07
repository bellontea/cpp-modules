#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (a.getY() - point.getY());
    Fixed cross2 = (b.getX() - point.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (b.getY() - point.getY());
    Fixed cross3 = (c.getX() - point.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (c.getY() - point.getY());

    if (cross1 > 0 && cross2 > 0 && cross3 > 0)
        return true;
    if (cross1 < 0 && cross2 < 0 && cross3 < 0)
        return true;
    return false;
}