#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>

class Bureaucrat
{
public:

    Bureaucrat( void );
	Bureaucrat( int grade, std::string name);
	Bureaucrat( const Bureaucrat &obj );
	~Bureaucrat();

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );

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