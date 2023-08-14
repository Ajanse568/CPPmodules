#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <iostream>

class WrongAnimal
{
public:

	WrongAnimal();
	WrongAnimal( const WrongAnimal &obj );
	~WrongAnimal();

	WrongAnimal &operator=( const WrongAnimal &obj );

	void	makeSound() const;
	std::string	getType() const;

protected:

	std::string	_type;

};

#endif