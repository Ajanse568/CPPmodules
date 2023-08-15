#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
public:

	Dog();
	Dog( const Dog &obj );
	~Dog();

	Dog &operator=( const Dog &obj );

	void	makeSound( void ) const;

private:

	Brain*	brain;

};

#endif