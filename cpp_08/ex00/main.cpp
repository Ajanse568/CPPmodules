//
// Created by allej on 12/11/2023.
//
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "easyfind(vector)" << std::endl << std::endl;
    std::cout << *easyfind(v, 2) << std::endl;
    std::cout << *easyfind(v, 3) << std::endl;
    try { std::cout << *easyfind(v, 4) << std::endl; }
    catch (std::exception &e) { std::cout << "Not found" << std::endl; }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::cout << std::endl << "easyfind(list)" << std::endl << std::endl;
    std::cout << *easyfind(l, 2) << std::endl;
    std::cout << *easyfind(l, 3) << std::endl;
    try { std::cout << *easyfind(l, 4) << std::endl; }
    catch (std::exception &e) { std::cout << "Not found" << std::endl; }
}