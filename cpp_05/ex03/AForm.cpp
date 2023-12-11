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
	std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm( const std::string name, const int signgrade, const int excgrade )
: _name(name), _signed(false), _sign_grade(signgrade), _exc_grade(excgrade)
{
	
	std::cout << "Param Form constructor called" << std::endl;
    if (signgrade < 1 || excgrade < 1)
        throw AForm::GradeTooHighException();
    else if (signgrade > 150 || excgrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj)
: _name(obj.getName()), _signed(isSigned()), _sign_grade(obj.getSignGrade()), _exc_grade(obj.getExcGrade())
{
	std::cout << "Form Copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Form Destructor called" << std::endl;
}

void    AForm::beSigned( const Bureaucrat &signee)
{
    if (signee.getGrade() > _sign_grade)
        throw AForm::GradeTooLowException();
    else
        _signed = true;
}

void    AForm::checkExec(int grade) const
{
    if (!isSigned())
        throw AForm::NotSignedException();
    if (grade > _exc_grade)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator = ( const AForm &obj )
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}