#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constractor called\n";
}

Brain::Brain(const Brain& other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    int i = 0;
    while (i < 100)
    {
        ideas[i] = other.ideas[i];
        i++;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destractor called\n";
}