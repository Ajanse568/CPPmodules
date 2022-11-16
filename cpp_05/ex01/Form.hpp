#ifndef __FORM_H__
#define __FORM_H__

#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
public:

	Form( const std::string name, const int signgrade, const int excgrade );
	Form( const Form &obj );
	~Form();

	void				beSigned( const Bureaucrat &signee);
	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExcGrade( void ) const;

private:

	const std::string	_name;
	bool				_signed;
	const int			_signgrade;
	const int			_excgrade;

	CustomException		GradeTooHighException;
	CustomException		GradeTooLowException;
	void				checkGrade( void );

};

std::ostream & operator << (std::ostream &out, const Form &c);

#endif