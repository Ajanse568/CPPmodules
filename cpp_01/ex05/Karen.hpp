#ifndef __KAREN_H__
#define __KAREN_H__

#include <iostream>

class Karen
{

private:

	void(Karen::*functptr[4])(void);
	std::string	levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );



public:

	Karen( void );
	~Karen( void );

	void	complain( std::string level );

};

#endif