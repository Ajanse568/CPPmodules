#include "AAForm.hpp"

AForm::AForm(void): _name(), _signed(false), _sign_grade(150), _exc_grade(150)
{
	std::cout << "Default constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
}

AForm::AForm( const std::string name, const int signgrade, const int excgrade )
: _name(name), _signed(false), _sign_grade(signgrade), _exc_grade(excgrade)
{
	
	std::cout << "Param constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
    if (signgrade < 1 || excgrade < 1)
        throw GradeTooHighException;
    else if (signgrade > 150 || excgrade > 150)
        throw GradeTooLowException;
}

AForm::AForm(const AForm &obj)
: _name(obj.getName()), _signed(isSigned()), _sign_grade(obj.getSignGrade()), _exc_grade(obj.getExcGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
}

void    AForm::beSigned( const Bureaucrat &signee)
{
    if (signee.getGrade() > _sign_grade)
        throw GradeTooLowException;
    else
        _signed = true;
}