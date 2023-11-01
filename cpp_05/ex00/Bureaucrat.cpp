#include "Bureaucrat.hpp"

CustomException &CustomException::operator=( const char* msg )
{
	this->_msg = msg;
	return (*this);
}

const char* CustomException::what() const throw()
{
	return (_msg);
}

Bureaucrat::Bureaucrat( void ): _name("none"), _grade(150)
{
	std::cout << "Default Bureau constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
}

Bureaucrat::Bureaucrat( int grade, const std::string name ): _name(name)
{
	std::cout << "Default Bureau constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
    if (grade < 1)
        throw GradeTooHighException;
    else if (grade > 150)
        throw GradeTooLowException;
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()), _grade(obj.getGrade())
{
	std::cout << "Copy constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}


const std::string	Bureaucrat::getName() const
{
	return(_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade( void )
{
    if (_grade == 1)
        throw GradeTooHighException;
    else
        _grade--;
}

void	Bureaucrat::decrementGrade( void )
{
    if (_grade == 150)
        throw GradeTooLowException;
    else
        _grade++;
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName();
	out << ", bureaucrat grade ";
	out << obj.getGrade();
	return (out);
}