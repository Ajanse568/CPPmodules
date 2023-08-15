#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	cat->makeSound();
	std::cout << std::endl;
	dog->makeSound();
	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	std::cout << std::endl;


	const WrongAnimal* metaWrong = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* catWrong = new WrongCat();
	std::cout << std::endl;

	std::cout << catWrong->getType() << std::endl;
	std::cout << std::endl;
	metaWrong->makeSound();
	catWrong->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;
	delete metaWrong;
	std::cout << std::endl;
	delete catWrong;
    std::cout << std::endl;

    Cat cats;
    std::cout << std::endl;
    Cat cats2(cats);
    std::cout << std::endl;
}