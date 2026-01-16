#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat p("Driss" ,1);
        Form F("wati9at for fuck saad", 5, 5);
        std::cout << p << std::endl;
        std::cout << F << std::endl;
        p.signForm(F);
        F.beSigned(p);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
}