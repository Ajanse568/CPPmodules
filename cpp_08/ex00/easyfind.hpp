//
// Created by allej on 12/11/2023.
//

#ifndef __EASYFIND_HPP
#define __EASYFIND_HPP

#include <iostream>

template <typename T> typename T::iterator easyfind(T &container, int n) {

    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
        if (*it == n)
            return (it);
    throw std::exception();
}
#endif //__EASYFIND_HPP
