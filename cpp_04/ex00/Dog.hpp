#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog: public Animal
{
public:

	Dog();
	Dog( const Dog &obj );
	~Dog();

	Dog &operator=( const Dog &obj );

	void	makeSound( void ) const;
};

#endif