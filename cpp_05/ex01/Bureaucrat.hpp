#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>

class Form;

class CustomException : public std::exception
{

private:

	const char*	_msg;

public:

	CustomException &operator=( const char* msg );

	virtual const char*	what() const throw();
};

class Bureaucrat
{
public:

	Bureaucrat( int grade, const std::string name );
	Bureaucrat( const Bureaucrat &obj );
	~Bureaucrat();

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );
	void				signForm(const Form &Form);

private:

	const std::string	_name;
	int					_grade;

	CustomException		GradeTooHighException;
	CustomException		GradeTooLowException;
	void				checkGrade( void );

};

std::ostream & operator << (std::ostream &out, const Bureaucrat &c);

#endif