#include "Cat.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
}

Cat& Cat::operator=(const Cat& other)
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
    std::cout << "Cat deleted\n";
}