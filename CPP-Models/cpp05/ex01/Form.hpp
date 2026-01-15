#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form
{
private:
    const std::string _name;
    bool _IsSigned;
    int _Sgrade;
    int _Egrade;
public:
    Form();
    Form(std::string name, int Sgrade, int Egrade);

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


#endif