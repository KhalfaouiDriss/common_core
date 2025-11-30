#include "fixed.hpp"

Fixed::Fixed()
{
    _fp = 0;
}

Fixed::Fixed(int n)
{
    _fp = n * 256;
}

Fixed::Fixed(float f)
{
    _fp = roundf(f * 256);
}

Fixed::Fixed(const Fixed &cp)
{
    *this = cp;
}

//============== operators ====================

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fp = other.getRawBits();
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

//  comparison operators

bool Fixed::operator>(const Fixed& other)
{
    return (this->_fp > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other)
{
    return (this->_fp < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other)
{
    return (this->_fp >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other)
{
    return (this->_fp <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other)
{
    return (this->_fp == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other)
{
    return (this->_fp != other.getRawBits());
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed Z;
    Z._fp = this->getRawBits() + other.getRawBits();
    return (Z);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed Z;
    Z._fp = this->getRawBits() - other.getRawBits();
    return (Z);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed Z;
    Z._fp = this->getRawBits() * other.getRawBits();
    return (Z);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed Z;
    Z._fp = this->getRawBits() / other.getRawBits();
    return (Z);
}

//  increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators

Fixed& Fixed::operator++(int)
{
    ++(this->_fp);
    return (*this);
}

Fixed& Fixed::operator++()
{
    (this->_fp)++;
    return (*this);
}

Fixed& Fixed::operator--(int)
{
    --(this->_fp);
    return (*this);
}

Fixed& Fixed::operator--()
{
    (this->_fp)--;
    return (*this);
}

// min() && max()

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    else
        return (a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (b);
    else
        return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    else
        return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (b);
    else
        return (a);
}


float Fixed::toFloat() const
{
    return ((float)_fp / 256);
}

int Fixed::toInt() const
{
    return (_fp / 256);
}

// Member functions

int Fixed::getRawBits( void ) const
{
    return (_fp);
}

void Fixed::setRawBits( int const raw )
{
    _fp = raw;
}

Fixed::~Fixed()
{
    (void)1;
}