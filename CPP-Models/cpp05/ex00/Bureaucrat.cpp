#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("void"), _grade(150)
{
    std::cout << "Bureaucrat " << _name << " Created\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if(grade < 1)
        throw 0;
    else if (grade > 150)
        throw 150;
    std::cout << "Bureaucrat " << _name << " Created\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{

}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{

}

Bureaucrat::~Bureaucrat()
{
}
