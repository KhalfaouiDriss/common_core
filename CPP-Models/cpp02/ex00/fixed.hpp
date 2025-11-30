#ifndef FIXED
#define FIXED
#include <iostream>
class Fixed
{
    private:
        int _fp;
        static const int _FractBit;
    public:
        Fixed();
        Fixed(const Fixed &cp);
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};






#endif