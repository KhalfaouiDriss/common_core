#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _Sgrade(150), _Egrade(150),  _IsSigned(false)
{
}

AForm::AForm(std::string name, int Sgrade, int Egrade) : _name(name), _Sgrade(Sgrade), _Egrade(Egrade), _IsSigned(false)
{
    if (_Sgrade > 150 || _Egrade > 150)
        throw GradeTooLowException();
    if (_Sgrade < 1 || _Egrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _Sgrade(other._Sgrade), _Egrade(other._Egrade), _IsSigned(other._IsSigned)
{

}

AForm& AForm::operator=(const AForm& other)
{  
    _IsSigned = other._IsSigned;
    return (*this);
}

std::string AForm::GetName() const
{
    return (_name);
}

int AForm::GetSgrade() const
{
    return (_Sgrade);
}

int AForm::GetEgrade() const
{
    return (_Egrade);
}
bool AForm::GetIsSigned() const
{
    return (_IsSigned);
}

void AForm::beSigned(Bureaucrat& B)
{
    if(_Sgrade < B.getGrade())
        throw AForm::GradeTooHighException();
    else
        _IsSigned = true;
    std::cout << " + " <<  B.getName() << " signed " << this->GetName() << "\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("* AForm Grade too hight!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("* AForm Grade too Low!");
}

const char* AForm::FormIsSingend::what() const throw()
{
    return ("AForm is not signed");
}

const char* AForm::FileOpen::what() const throw()
{
    return ("File not Opened");
}

std::ostream& operator<<(std::ostream& os, const AForm& F)
{
    os << "AForm Name " << F.GetName() << "\n"
       << " - Signed: " << (F.GetIsSigned() ? "Yes" : "No") << '\n'
       << " - Sign grade required: " << F.GetSgrade() << '\n'
       << " - Execute grade required: " << F.GetEgrade();
    return os;
}


AForm::~AForm()
{
}