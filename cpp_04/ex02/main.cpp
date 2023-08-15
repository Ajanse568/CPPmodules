#include "Dog.hpp"
#include "Cat.hpp"

int	main( void )
{
//	Animal a;
//
//    a.makeSound();
    Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

    std::cout << std::endl;
    for (int i = 0; i < 4; i++){
        delete animals[i];
        std::cout << std::endl;
    }

    return 0;
}