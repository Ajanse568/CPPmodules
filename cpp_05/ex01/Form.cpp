#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade too low");
}

Form::Form(void): _name(), _signed(false), _sign_grade(150), _exc_grade(150)
{
}

Form::Form( const std::string name, const int signgrade, const int excgrade )
: _name(name), _signed(false), _sign_grade(signgrade), _exc_grade(excgrade)
{
    if (signgrade < 1 || excgrade < 1)
        throw Form::GradeTooHighException();
    else if (signgrade > 150 || excgrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &obj)
: _name(obj.getName()), _signed(isSigned()), _sign_grade(obj.getSignGrade()), _exc_grade(obj.getExcGrade())
{
}

Form::~Form(void)
{
}

Form & Form::operator = (const Form &obj)
{
    if (this == &obj)
        return (*this);
    this->_signed = obj.isSigned();
    return (*this);
}

const std::string	Form::getName() const
{
    return(this->_name);
}

bool	Form::isSigned() const
{
    return (this->_signed);
}

int	Form::getSignGrade() const
{
    return (this->_sign_grade);
}

int	Form::getExcGrade() const
{
    return (this->_exc_grade);
}

void    Form::beSigned( const Bureaucrat &signee)
{
    if (signee.getGrade() > this->_sign_grade)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream & operator << (std::ostream &out, const Form &c) {
    out << c.getName();
    if (c.isSigned())
        out << " is signed, ";
    else
        out << " is not signed, ";
    out << "sign grade " << c.getSignGrade() << " and exc grade " << c.getExcGrade() << ".";
    return (out);

}