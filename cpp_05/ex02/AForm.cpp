#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw() {
    return ("Form is not signed");
}

AForm::AForm(void): _name(), _signed(false), _sign_grade(150), _exc_grade(150)
{
}

AForm::AForm( const std::string name, const int signgrade, const int excgrade )
: _name(name), _signed(false), _sign_grade(signgrade), _exc_grade(excgrade)
{
    if (signgrade < 1 || excgrade < 1)
        throw AForm::GradeTooHighException();
    else if (signgrade > 150 || excgrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj)
: _name(obj.getName()), _signed(isSigned()), _sign_grade(obj.getSignGrade()), _exc_grade(obj.getExcGrade())
{
}

AForm::~AForm(void)
{
}

AForm & AForm::operator = (const AForm &obj)
{
    if (this == &obj)
        return (*this);
    this->_signed = obj.isSigned();
    return (*this);
}

const std::string	AForm::getName() const
{
    return(this->_name);
}

bool	AForm::isSigned() const
{
    return (this->_signed);
}

int	AForm::getSignGrade() const
{
    return (this->_sign_grade);
}

int	AForm::getExcGrade() const
{
    return (this->_exc_grade);
}


void    AForm::beSigned( const Bureaucrat &signee)
{
    if (signee.getGrade() > this->_sign_grade)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

void    AForm::checkExec(int grade) const
{
    if (!isSigned())
        throw AForm::NotSignedException();
    if (grade > this->_exc_grade)
        throw AForm::GradeTooLowException();
}

std::ostream & operator << (std::ostream &out, const AForm &c) {
    out << c.getName();
    if (c.isSigned())
        out << " is signed, ";
    else
        out << " is not signed, ";
    out << "sign grade " << c.getSignGrade() << " and exc grade " << c.getExcGrade() << ".";
    return (out);

}