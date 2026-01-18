#ifndef INTERN_HPP
#define INTERN_HPP

class AForm;
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
private:
    
public:
    Intern();
    AForm *makeForm(std::string AFormName, std::string target);
    class FormNotFound : public std::exception
    {
        const char *what() const throw();
    };
    ~Intern();
};


AForm *makeRobotomy(std::string AFormName, std::string target);
AForm *makeShrubberey(std::string AFormName, std::string target);
AForm *makePresidential(std::string AFormName, std::string target);

#endif