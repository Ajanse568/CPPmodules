#include "Form.hpp"

Form::Form(void): _name(), _signed(false), _signgrade(150), _excgrade(150)
{
	std::cout << "Default constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
}

Form::Form( const std::string name, const int signgrade, const int excgrade )
: _name(name), _signed(false), _signgrade(signgrade), _excgrade(excgrade)
{
	std::cout << "Param constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
}

Form::Form(const Form &obj)
: _name(obj.getName), _signed(false), _signgrade(obj.getSignGrade()), _excgrade(obj.getExcGrade())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
}

