#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const int _Sgrade;
    const int _Egrade;
    bool _IsSigned;
public:
    AForm();
    AForm(std::string name, int Sgrade, int Egrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

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
    class FormIsSingend : public std::exception {
    public:
        const char *what() const throw();
    };
    class FileOpen : public std::exception {
    public:
        const char *what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;

    virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& F);

#endif