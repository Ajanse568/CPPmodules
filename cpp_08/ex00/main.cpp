//
// Created by allej on 12/11/2023.
//
#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {

        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        std::cout << *easyfind(v, 2) << std::endl;
        std::cout << *easyfind(v, 3) << std::endl;
    try { std::cout << *easyfind(v, 4) << std::endl; }
    catch (std::exception &e) { std::cout << "Not found" << std::endl; }
}