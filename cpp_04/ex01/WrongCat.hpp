#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:

	WrongCat();
	WrongCat( const WrongCat &obj );
	~WrongCat();

	WrongCat &operator=( const WrongCat &obj );

	void	makeSound( void ) const;
};

#endif