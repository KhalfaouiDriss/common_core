#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal(other)
{
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
    WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "meaw\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat deleted\n";
}