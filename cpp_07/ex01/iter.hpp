//
// Created by allej on 12/11/2023.
//

#ifndef __ITER_HPP
#define __ITER_HPP

#include <iostream>

template<typename T, typename Y> void iter(T *array, size_t length, Y f) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template < typename T >
int    print( T &i )
{
    std::cout << i << std::endl;
    return 1;
}

#endif //__ITER_HPP
