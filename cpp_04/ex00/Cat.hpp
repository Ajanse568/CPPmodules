#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat: public Animal
{
public:

	Cat();
	Cat( const Cat &obj );
	~Cat();

	Cat &operator=( const Cat &obj );

	void	makeSound( void ) const;
};

#endif