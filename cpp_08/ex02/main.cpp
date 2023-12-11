 //
// Created by allej on 12/11/2023.
//

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
//    std::cout << mstack.top() << std::endl;
//    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return 0;
}