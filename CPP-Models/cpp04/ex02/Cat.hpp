#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brn;
public:
    Cat();
    Cat(Cat& other);
    Cat& operator=(Cat& other);
    void makeSound() const;
    ~Cat();
};


#endif