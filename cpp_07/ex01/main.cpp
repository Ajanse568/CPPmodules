//
// Created by allej on 12/11/2023.
//
#include "iter.hpp"

void    multiply_by_2(int &i) {
     i *= 2;
}

int main() {
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: " << std::endl;
    iter(arr1, 5, multiply_by_2);
    iter(arr1, 5, print<int>);


    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: " << std::endl;
    iter(arr4, 5, print<std::string>);

    return 0;
}
