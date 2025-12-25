#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    _brn = new Brain();
    std::cout << "Cat created\n";
}

Cat::Cat(Cat& other) : Animal(other)
{
}

Cat& Cat::operator=(Cat& other)
{
    Animal::operator=(other);
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