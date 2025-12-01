#include "Point.hpp"
#include <cmath>

static float area(Point const &a, Point const &b, Point const &c)
{
    float ax = a.getX().toFloat();
    float ay = a.getY().toFloat();
    float bx = b.getX().toFloat();
    float by = b.getY().toFloat();
    float cx = c.getX().toFloat();
    float cy = c.getY().toFloat();

    return fabs(
        ax * (by - cy) +
        bx * (cy - ay) +
        cx * (ay - by)
    ) / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A (area(a, b, c));
    Fixed A1(area(point, a, b));
    Fixed A2(area(point, b, c));
    Fixed A3(area(point, c, a));

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;

    Fixed sum(A1 + A2 + A3);
    if (sum == A)
        return true;
    else
        return false;
}
