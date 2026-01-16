#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{ 
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    void execute(Bureaucrat const & executor) const;

    ~RobotomyRequestForm();
};




#endif