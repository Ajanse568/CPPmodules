//
// Created by allej on 12/11/2023.
//

#ifndef __ARRAY_HPP
#define __ARRAY_HPP

#include <iostream>

template <class T> class Array {

public:

    Array() : _array(NULL), _size(0) {}
    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    Array(const Array &obj) : _array(NULL), _size(0) { *this = obj; }
    ~Array() { delete [] _array; }

    Array &operator=(const Array &obj) {
        if (this != &obj) {
            delete [] _array;
            _array = new T[obj._size];
            _size = obj._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = obj._array[i];
        }
        return *this;
    }

    T &operator[](unsigned int i) {
        if (i >= _size)
            throw std::exception();
        return _array[i];
    }

    unsigned int size() const { return _size; }

private:

        T *_array;
        unsigned int _size;
};

#endif //__ARRAY_HPP
