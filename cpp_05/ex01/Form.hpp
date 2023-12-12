#ifndef __FORM_H__
#define __FORM_H__

#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:

	Form( void );
	Form( const std::string name, const int signgrade, const int excgrade );
	Form( const Form &obj );
	~Form();

	Form &operator = ( const Form &obj );

	void				beSigned ( const Bureaucrat &signee);
	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExcGrade( void ) const;

private:

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exc_grade;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() ;
    } ;
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() ;
    } ;

};

std::ostream & operator << (std::ostream &out, const Form &c);

#endif