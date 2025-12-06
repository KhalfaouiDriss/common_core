#include "fixed.hpp"
#include <iomanip>

int main(void)
{
    //     Fixed a(0.2f);
    //     Fixed b(0.1f);
    //     Fixed e(0.3f);

    //     float d = 0.2;
    //     float c = 0.1;
    //     float s = 0.3;

    //    std::cout << ((a + b) == e) << std::endl;
    //    std::cout << ((d + c) == s) << std::endl;
    //    std::cout << ((0.01 + 0.01 + 0.01 + 0.01 + 0.01 + 0.01 + 0.01 + 0.01 + 0.01) == (0.09)) << std::endl;

    float d = 1.0;
    Fixed a(1.0f);
    Fixed b(0.01f);
    int i = -1;
    while(++i < 10000)
        d += 0.01;
        // a = a + b;

    std::cout << std::setprecision(200) << a << std::endl;

    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}