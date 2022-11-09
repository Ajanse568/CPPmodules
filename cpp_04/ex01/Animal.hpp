#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>

class Animal
{
public:

	Animal();
	Animal( const Animal &obj );
	virtual ~Animal();

	Animal &operator=( const Animal &obj );

	virtual void	makeSound() const;
	virtual std::string	getType() const;

protected:

	std::string	type;

};

#endif