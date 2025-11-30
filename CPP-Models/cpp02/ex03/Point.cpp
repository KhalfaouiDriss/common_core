#include "Point.hpp"

Point::Point()
{
    x.setRawBits(0);
    y.setRawBits(0);
}

Point::Point(float a, float b)
{
    x.setRawBits(a);
    y.setRawBits(b);
}

Point::Point(Point& other)
{
    *this = other;
}

Point& Point::operator=(Point& other)
{
    this->x = other.x;
    this->y = other.y;
}

Point::~Point()
{
}