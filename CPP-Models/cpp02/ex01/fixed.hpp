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

        Fixed& operator=(const Fixed& other); // Copy assignment

        float toFloat(void) const;
        int   toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif