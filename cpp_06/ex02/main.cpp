//
// Created by allej on 12/11/2023.
//

#include "Classes.hpp"
#include <iostream>

int main() {
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}