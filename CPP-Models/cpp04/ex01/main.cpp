#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *A[10];
    int f = -1;
    while (++f < 10)
    {
        if(f < 5)
            A[f] = new Cat();
        else
            A[f] = new Dog();
    }
    f = -1;
    while (++f < 10)
    {
        if(f < 5)
            delete A[f];
        else
            delete A[f];
    }
}   