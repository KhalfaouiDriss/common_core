#include "Point.hpp"

static float sign(Point const p1, Point const p2, Point const p3)
{
    return (
        (p1.getX().toFloat() - p3.getX().toFloat()) *
        (p2.getY().toFloat() - p3.getY().toFloat()) -
        (p2.getX().toFloat() - p3.getX().toFloat()) *
        (p1.getY().toFloat() - p3.getY().toFloat())
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float d1 = sign(point, a, b);
    float d2 = sign(point, b, c);
    float d3 = sign(point, c, a);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // If any of the signs is zero → on edge → must return false
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;

    return !(hasNeg && hasPos); // true if inside
}
