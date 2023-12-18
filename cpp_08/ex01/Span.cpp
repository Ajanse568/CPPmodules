//
// Created by allej on 12/11/2023.
//

#include "Span.hpp"
#include <algorithm>

Span& Span::operator=(const Span &obj) {
    if (this != &obj) {
        _size = obj.size();
        _array = obj.getContainer();
    }
    return *this;
}

Span::Span(const Span &obj): _size(obj.size()) {*this = obj;};
Span::Span(unsigned int n) : _size(n) {};

Span::~Span() {};

void Span::addNumber(int n) {
    if (_array.size() == _size)
        throw std::exception();
    _array.push_back(n);
}

int Span::shortestSpan() {
    if (_array.size() <= 1)
        throw std::exception();
    std::vector<int> tmp(_array);
    std::sort(tmp.begin(), tmp.end());
    return(tmp[1] - tmp[0]);
}

int Span::longestSpan() {
    if (_array.size() <= 1)
        throw std::exception();
    std::vector<int> tmp(_array);
    std::sort(tmp.begin(), tmp.end());
    return(tmp[tmp.size() - 1] - tmp[0]);
}

unsigned int    Span::size() const{
    return this->_size;
}

std::vector<int>    Span::getContainer() const {
    return this->_array;
}