#ifndef POINT_HPP
#define POINT_HPP

#include "fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    Point();                                    // default constructor
    Point(const float x, const float y);        // float constructor
    Point(const Point &other);                  // copy constructor
    Point &operator=(const Point &other);       // copy assignment
    ~Point();                                   // destructor

    Fixed getX() const;
    Fixed getY() const;
};

#endif
