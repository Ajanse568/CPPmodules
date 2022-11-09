#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	const Cat* cat = new Cat();
	Cat cat2;

	cat2 = *cat;
	cat->pickBrain();
	cat2.pickBrain();
	delete cat;

}