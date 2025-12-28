#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* j = new Dog();
    Animal* i = new Cat();
    Animal K;
    delete j;
    delete i;
}