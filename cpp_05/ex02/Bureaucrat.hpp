#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>

class AForm;

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

    Bureaucrat( void );
	Bureaucrat( int grade, const std::string name );
	Bureaucrat( const Bureaucrat &obj );
	~Bureaucrat();

	Bureaucrat &operator=( const Bureaucrat &obj);

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );
	void				signForm(AForm &AForm);

private:

	const std::string	_name;
	int					_grade;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() ;
    } ;
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() ;
    } ;

};

std::ostream & operator << (std::ostream &out, const Bureaucrat &c);

#endif