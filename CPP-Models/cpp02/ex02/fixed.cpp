#include "fixed.hpp"

// Constructors

Fixed::Fixed() : _fp(0)
{
}

Fixed::Fixed(int n)
{
    _fp = n << _fractionalBits;  // n * 256
}

Fixed::Fixed(float f)
{
    _fp = roundf(f * 256);
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

// Destructor

Fixed::~Fixed()
{
}

// Assignment operator

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fp = other._fp;

    return *this;
}

// Comparison operators

bool Fixed::operator>(const Fixed& other) const  { return (this->_fp > other._fp); }
bool Fixed::operator<(const Fixed& other) const  { return (this->_fp < other._fp); }
bool Fixed::operator>=(const Fixed& other) const { return (this->_fp >= other._fp); }
bool Fixed::operator<=(const Fixed& other) const { return (this->_fp <= other._fp); }
bool Fixed::operator==(const Fixed& other) const { return (this->_fp == other._fp); }
bool Fixed::operator!=(const Fixed& other) const { return (this->_fp != other._fp); }

// Arithmetic operators 

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    res._fp = this->_fp + other._fp;
    return res;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    res._fp = this->_fp - other._fp;
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    long tmp = (long)this->_fp * (long)other._fp;
    res._fp = tmp >> _fractionalBits;
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed res;
    long tmp = ((long)this->_fp << _fractionalBits);
    res._fp = tmp / other._fp;
    return res;
}

// Increment / Decrement

Fixed& Fixed::operator++()
{
    _fp++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fp++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _fp--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fp--;
    return temp;
}

// min / max

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

float Fixed::toFloat() const
{
    return (float)_fp / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _fp >> _fractionalBits;
}

int Fixed::getRawBits() const
{
    return _fp;
}

void Fixed::setRawBits(int const raw)
{
    _fp = raw;
}

// ostream operator <<

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return os;
}