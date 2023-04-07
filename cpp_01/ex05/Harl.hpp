#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl
{

private:

	void(Harl::*functptr[4])(void);
	std::string	levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );



public:

	Harl( void );
	~Harl( void );

	void	complain( std::string level );

};

#endif