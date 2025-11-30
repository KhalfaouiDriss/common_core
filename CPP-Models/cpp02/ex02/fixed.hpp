#ifndef FIXED
#define FIXED
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fp;
        static const int    _FractBit = 8;

    public:
        Fixed();                    // Default constructor
        Fixed(int n);               // Int constructor
        Fixed(float f);             // Float constructor
        Fixed(const Fixed &cp);     // Copy constructor

        Fixed& operator=(const Fixed& other);
        //  comparison operators
        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);
        // arithmetic operators
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);
        // increment/decrement
        Fixed& operator++(int);
        Fixed& operator++();
        Fixed& operator--(int);
        Fixed& operator--();

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        float toFloat(void) const;
        int   toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif