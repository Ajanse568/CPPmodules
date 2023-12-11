//
// Created by allej on 12/11/2023.
//

#ifndef __MUTANTSTACK_HPP
#define __MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

    public:

    MutantStack() : std::stack<T>() {};
    MutantStack(const MutantStack &obj) : std::stack<T>(obj) {};
    ~MutantStack() {};

    MutantStack &operator=(const MutantStack &obj) {
        if (this == &obj)
            return *this;
        std::stack<T>::operator=(obj);
        return *this;
    };

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    };

    iterator end() {
        return std::stack<T>::c.end();
    };
};

#endif //__MUTANTSTACK_HPP
