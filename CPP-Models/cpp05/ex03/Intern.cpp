#include "Intern.hpp"

Intern::Intern()
{
}

const char *Intern::FormNotFound::what() const throw()
{
    return ("Form not found!!!");
}

AForm *makeRobotomy(std::string AFormName, std::string target)
{
    std::cout << "Intern creates " << AFormName << std::endl;
    return (new RobotomyRequestForm(target));
}

AForm *makeShrubberey(std::string AFormName, std::string target)
{
    std::cout << "Intern creates " << AFormName << std::endl;
    return (new ShrubberyCreationForm(target));
}

AForm *makePresidential(std::string AFormName, std::string target)
{
    std::cout << "Intern creates " << AFormName << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string AFormName, std::string target)
{
    std::string targ[3] = {"robotomy request", "shrubberey request", "presidential request"};
    AForm *(*fct[3])(std::string AFormName, std::string target) = 
    {
        &makeRobotomy,
        &makeShrubberey,
        &makePresidential
    }; 
    int i = -1;
    while (++i < 3)
        if (AFormName == targ[i])
            return (fct[i](AFormName, target));
    throw FormNotFound();
    return (NULL);
}

Intern::~Intern()
{
}