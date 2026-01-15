#include "Form.hpp"

Form::Form() : _name("Default"), _Sgrade(150), _Egrade(150)
{
}

Form::Form(std::string name, int Sgrade, int Egrade) : _name(name), _Sgrade(Sgrade), _Egrade(Egrade)
{
    if (_Sgrade > 150 || _Egrade > 150)
        throw GradeTooLowException();
    if (_Sgrade < 1 || _Egrade < 1)
        throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade too hight!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade too Low!");
}

Form::~Form()
{
}