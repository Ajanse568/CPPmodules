#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low");
}


Bureaucrat::Bureaucrat( void ): _name("none"), _grade(150)
{
    std::cout << "Default Bureau constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( int grade, const std::string name ): _name(name)
{
    std::cout << "Default Bureau constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()), _grade(obj.getGrade())
{
    std::cout << "Copy constructor called" << std::endl;
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
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void	Bureaucrat::decrementGrade( void )
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void    Bureaucrat::signForm(Form &Form)
{
    try {
        Form.beSigned(*this);
        std::cout << _name << " signed " << Form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << Form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName();
    out << ", bureaucrat grade ";
    out << obj.getGrade()<< ".";
    return (out);
}
