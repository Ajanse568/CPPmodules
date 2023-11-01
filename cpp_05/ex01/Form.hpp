#ifndef __FORM_H__
#define __FORM_H__

#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class CustomException;

class Form
{
public:

	Form( void );
	Form( const std::string name, const int signgrade, const int excgrade );
	Form( const Form &obj );
	~Form();

	void				beSigned ( const Bureaucrat &signee);
	const std::string	getName( void ) const { return _name;};
	bool				isSigned( void ) const { return _signed; };
	int					getSignGrade( void ) const { return _sign_grade; };
	int					getExcGrade( void ) const  { return _exc_grade; };

private:

	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exc_grade;

	CustomException		GradeTooHighException;
	CustomException		GradeTooLowException;
};

std::ostream & operator << (std::ostream &out, const Form &c);

#endif