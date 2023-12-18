//
// Created by allej on 12/11/2023.
//

#include "Span.hpp"
#include <list>
#include <iostream>
#include <cstdlib>

int main() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);

    std::list<int> v;
    v.push_back(17);
    v.push_back(9);
    v.push_back(11);

    sp.addNumbers(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span spanBig(10003);
    std::srand(time(0));

    for (int i = 0; i < 10000; i++)
        v.push_back(std::rand());
    spanBig.addNumbers(v.begin(), v.end());

    try{
        sp.addNumbers(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Error!" << std::endl;
    }
    try{
        sp.addNumber(6);
    } catch (const std::exception& e) {
        std::cout << "Error!" << std::endl;
    }
}