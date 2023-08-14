#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

    std::cout << std::endl;
    for (int i = 0; i < 4; i++){
        delete animals[i];
        std::cout << std::endl;
    }

//    WrongAnimal *wrong_animals[4] = {new WrongCat(), new WrongCat(), new WrongCat(), new WrongCat()};
//
//    for (int i = 0; i < 4; i++){
//        delete wrong_animals[i];
//        std::cout << std::endl;
//    }

    Cat cat;
    Cat cat2(cat);

    system("leaks beestenboel");
    return 0;
}