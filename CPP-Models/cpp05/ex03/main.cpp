#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat alex("Driss", 1);
        Intern jon;
        AForm* sign = jon.makeForm("robotomy request", "Sign");

        std::cout << *sign << std::endl;
        alex.executeForm(*sign);
        alex.signAForm(*sign);
        std::cout << *sign << std::endl;
        delete (sign);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}