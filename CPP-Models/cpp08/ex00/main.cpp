#include <iostream>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::list<int> flok;

    flok.push_back(10);
    flok.push_back(20);
    flok.push_back(30);
    flok.push_back(40);

    std::list<int>::iterator it = flok.begin();

    it = easyfind(flok, 20);

    std::cout << *it;
}