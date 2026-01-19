#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (GetIsSigned() == false)
        throw AForm::FormIsSingend();
    if (GetEgrade() < executor.getGrade())
        throw AForm::GradeTooHighException();
    
    std::cout << "* LOUD DRILLING NOISES *" << std::endl;
    int i = rand();
    if (i % 2)
        std::cout << GetName() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << GetName() << " failed!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}