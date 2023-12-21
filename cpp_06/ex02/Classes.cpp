//
// Created by allej on 12/18/2023.
//
#include "Classes.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void) {
    std::srand(time(NULL));
    int random = std::rand() % 3;

    if (random == 0) {
        std::cout << "A class generated" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "B class generated" << std::endl;
        return new B();
    } else {
        std::cout << "C class generated" << std::endl;
        return new C();
    }
}

void    identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
}

void    identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception &e) {
            try {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Error" << std::endl;
            }
        }
    }
}
