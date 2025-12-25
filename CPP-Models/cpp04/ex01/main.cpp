#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    Animal* j = new Dog();
    Animal* i = new Cat();
    Animal A[10];
    int f = -1;
    while (++f < 10)
    {
        A[f] = new Cat(); 
    }
    
    delete j;
    delete i;
}   