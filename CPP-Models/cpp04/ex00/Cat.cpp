#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat created\n";
}

void Cat::makeSound()
{
    std::cout << "meaw\n";
}

Cat::~Cat()
{
    std::cout << "Cat deleted\n";
}