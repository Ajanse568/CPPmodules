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

Bureaucrat::Bureaucrat( int grade , const std::string name): _name(name), _grade(grade)
{
	std::cout << "Default Bureau constructor called" << std::endl;
	GradeTooHighException = "Grade will be too high";
	GradeTooLowException = "Grade will be too low";
	checkGrade();
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

void	Bureaucrat::checkGrade( void)
{
	if (_grade < 1)
		throw GradeTooHighException;
	else if (_grade > 150)
		throw GradeTooLowException;
}

void	Bureaucrat::incrementGrade( void )
{
	_grade--;
	checkGrade();
}

void	Bureaucrat::decrementGrade( void )
{
	_grade++;
	checkGrade();
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName();
	out << ", bureaucrat grade ";
	out << obj.getGrade();
	return (out);
}