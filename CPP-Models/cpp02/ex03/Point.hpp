#ifndef POINT_HPP
#define POINT_HPP

#include "fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point(float a, float b);
        Point(Point& other);
        Point& operator=(Point& other);
        ~Point();
};









#endif