#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat created\n";
    _brn = new Brain();
}

Cat::Cat(Cat& other) : Animal(other)
{
    std::cout << "Copy Constractor: Cat created\n";
    this->_brn = new Brain(*(other._brn));
}

Cat& Cat::operator=(Cat& other)
{
    Animal::operator=(other);
    *_brn = *other._brn;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "meaw\n";
}

Cat::~Cat()
{
    delete _brn;
    std::cout << "Cat deleted\n";
}