#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (GetIsSigned() == false)
        throw AForm::FormIsSingend();
    if (GetEgrade() < executor.getGrade())
        throw AForm::GradeTooHighException();
    
    std::string name = GetName() + "_shrubbery";
    std::ofstream of(name.c_str());
    if(!of)
        throw FileOpen();

    of <<
        "       ccee88oo\n"
        "  C8O8O8Q8PoOb o8oo\n"
        " dOB69QO8PdUOpugoO9bD\n"
        "CgggbU8OU qOp qOdoUOdcb\n"
        "    6OuU  /p u gcoUodpP\n"
        "      \\\\//  /douUP\n"
        "        \\\\\\\\\\/\n"
        "         |||/\\\n"
        "         |||\\/\n"
        "         |||||\n"
        "   .....//||||\\....\n";
    of.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}