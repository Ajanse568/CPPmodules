#ifndef __AForm_H__
# define __AForm_H__

#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class CustomException;

class AForm
{
public:

	AForm( void );
	AForm( const std::string name, const int signgrade, const int excgrade );
	AForm( const AForm &obj );
	~AForm();

	AForm &operator = ( const AForm &obj );

	void				beSigned ( const Bureaucrat &signee);
	const std::string	getName( void ) const { return _name;};
	bool				isSigned( void ) const { return _signed; };
	int					getSignGrade( void ) const { return _sign_grade; };
	int					getExcGrade( void ) const  { return _exc_grade; };
	void				checkExec(int grade) const;
    virtual void        execute(Bureaucrat const & executor) const = 0;

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
	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() ;
	} ;
};

std::ostream & operator << (std::ostream &out, const AForm &c);

#endif