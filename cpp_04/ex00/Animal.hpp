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
	std::string	getType() const;

protected:

	std::string	_type;

};

#endif