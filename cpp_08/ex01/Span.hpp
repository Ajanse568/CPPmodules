//
// Created by allej on 12/11/2023.
//

#ifndef __SPAN_HPP
#define __SPAN_HPP

#include <iostream>
#include <vector>

class Span {

public:

        Span(unsigned int n);
        Span(const Span &obj);
        ~Span();

        Span &operator=(const Span &obj);

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        unsigned int        size() const;
        std::vector<int>    getContainer() const;

        template <class InputIterator>
        void addNumbers(InputIterator first, InputIterator last)
        {
            if (_array.size() + std::distance(first, last) > _size)
                throw std::exception();
            _array.insert(_array.end(), first, last);
        };

private:

            Span();
            unsigned int _size;
            std::vector<int> _array;
};


#endif //__SPAN_HPP
