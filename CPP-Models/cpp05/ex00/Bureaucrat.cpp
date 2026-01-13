#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
};


#endif
