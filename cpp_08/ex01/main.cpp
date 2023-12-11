//
// Created by allej on 12/11/2023.
//

#include "Span.hpp"
#include <list>

int main() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);

    std::list<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    sp.addNumbers(v.begin(), v.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

}