#include <iostream> 
#include "Span.hpp"

// int main()
// {
//     Span sp(3);
//     // std::vector<int> list  = {
//     //     742, 118, 934, 256, 589, 812, 303, 647, 491, 125, 876, 534, 219, 985, 402, 673, 158, 761, 320, 545,
//     //     898, 205, 612, 947, 331, 704, 151, 820, 439, 611, 794, 238, 509, 666, 125, 950, 483, 717, 392, 558,
//     //     106, 472, 811, 330, 969, 214, 845, 636, 160, 522, 797, 304, 573, 914, 227, 609, 421, 813, 187, 565,
//     //     111, 464, 735, 302, 928, 518, 831, 377, 693, 204, 719, 407, 581, 903, 259, 648, 473, 116, 856, 504,
//     //     108, 416, 756, 383, 999, 210, 804, 349, 625, 126, 740, 438, 976, 315, 652, 910, 527, 599, 702, 143
//     // };

//     std::vector<int> list  = {1, 90, 80};
    

//     sp.addNumbers(list);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
// }

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}