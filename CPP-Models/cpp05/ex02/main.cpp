#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
    srand(time(NULL));
    try
    {
        Bureaucrat p("Driss" ,1);
        // PresidentialPardonForm Per("saad");
        RobotomyRequestForm Rob("Jobyden");
        // ShrubberyCreationForm shr("Ayman");
        std::cout << p << std::endl;
        // std::cout << Per << std::endl;
        // Per.execute(p);
        // Rob.execute(p);
        p.signAForm(Rob);
        p.executeForm(Rob);
        // p.signAForm(shr);
        // shr.execute(p);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
}