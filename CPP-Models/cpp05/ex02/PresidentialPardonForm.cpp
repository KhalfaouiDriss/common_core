#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (GetIsSigned() == false)
        throw AForm::FormIsSingend();
    if (GetEgrade() < executor.getGrade())
        throw AForm::GradeTooHighException();
    std::cout << "-> " << GetName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {}