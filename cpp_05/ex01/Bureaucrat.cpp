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
}

Bureaucrat::Bureaucrat( int grade, const std::string name ): _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName()), _grade(obj.getGrade())
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &obj)
{
    if (this == &obj)
        return (*this);
    this->_grade = obj.getGrade();
    return (*this);
}

const std::string	Bureaucrat::getName() const
{
    return(this->_name);
}

int	Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void	Bureaucrat::incrementGrade( void )
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

void    Bureaucrat::signForm(Form &Form)
{
    try {
        Form.beSigned(*this);
        std::cout << this->_name << " signed " << Form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << Form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName();
    out << ", bureaucrat grade ";
    out << obj.getGrade()<< ".";
    return (out);
}
