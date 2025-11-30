#include "fixed.hpp"

Fixed::Fixed()
{
    _fp = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
    std::cout << "int constructor called" << std::endl;
    _fp = n * 256;
}

Fixed::Fixed(float f)
{
    std::cout << "float constructor called" << std::endl;
    _fp = roundf(f * 256);
}

Fixed::Fixed(const Fixed &cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fp = other.getRawBits();
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


float Fixed::toFloat() const
{
    return ((float)_fp / 256);
}

int Fixed::toInt() const
{
    return (_fp / 256);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_fp);
}

void Fixed::setRawBits( int const raw )
{
    _fp = raw;
    // std::cout << "setRawBits member function called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}