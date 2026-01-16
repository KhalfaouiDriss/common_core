#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    const int _Sgrade;
    const int _Egrade;
    bool _IsSigned;
public:
    Form();
    Form(std::string name, int Sgrade, int Egrade);
    Form(const Form& other);
    Form& operator=(const Form& other);

    std::string GetName() const;
    int GetSgrade() const;
    int GetEgrade() const;
    bool GetIsSigned() const;

    void beSigned(Bureaucrat& B);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& F);

#endif