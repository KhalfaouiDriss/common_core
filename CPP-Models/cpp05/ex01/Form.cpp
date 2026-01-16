#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _Sgrade(150), _Egrade(150),  _IsSigned(false)
{
}

Form::Form(std::string name, int Sgrade, int Egrade) : _name(name), _Sgrade(Sgrade), _Egrade(Egrade), _IsSigned(false)
{
    if (_Sgrade > 150 || _Egrade > 150)
        throw GradeTooLowException();
    if (_Sgrade < 1 || _Egrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _Sgrade(other._Sgrade), _Egrade(other._Egrade), _IsSigned(other._IsSigned)
{

}

Form& Form::operator=(const Form& other)
{  
    _IsSigned = other._IsSigned;
    return (*this);
}

std::string Form::GetName() const
{
    return (_name);
}

int Form::GetSgrade() const
{
    return (_Sgrade);
}

int Form::GetEgrade() const
{
    return (_Egrade);
}
bool Form::GetIsSigned() const
{
    return (_IsSigned);
}

void Form::beSigned(Bureaucrat& B)
{
    if(_Sgrade < B.getGrade())
        throw Form::GradeTooHighException();
    else
        _IsSigned = true;
    std::cout << B.getName() << " signed " << this->GetName() << "\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("* Form Grade too hight!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("* Form Grade too Low!");
}

std::ostream& operator<<(std::ostream& os, const Form& F)
{
    os << "Form Name " << F.GetName() << "\n"
       << " - Signed: " << (F.GetIsSigned() ? "Yes" : "No") << '\n'
       << " - Sign grade required: " << F.GetSgrade() << '\n'
       << " - Execute grade required: " << F.GetEgrade();
    return os;
}


Form::~Form()
{
}