#ifndef INTERN_HPP
#define INTERN_HPP

class AForm;
#include <iostream>

class Intern
{
private:
    
public:
    Intern();
    AForm *makeForm(std::string AFormName, std::string target);
    ~Intern();
};

Intern::Intern()
{
}

AForm *Intern::makeForm(std::string AFormName, std::string target)
{
    std::string targ[3] = {"robotomy request", "shrubberey request", "presidential request"};
    AForm (*fct[3])() = 
    {
        
    }; 
}

Intern::~Intern()
{
}


#endif