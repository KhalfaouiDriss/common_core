#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point outside(10, 10);
    Point onEdge(5, 0);

    bsp(a, b, c, inside) ? std::cout << "Inside: true" << std::endl : std::cout << "Inside: false" << std::endl;
    bsp(a, b, c, outside) ? std::cout << "Inside: true" << std::endl : std::cout << "Inside: false" << std::endl;
    bsp(a, b, c, onEdge) ? std::cout << "Inside: true" << std::endl : std::cout << "Inside: false" << std::endl;

    return 0;
}

