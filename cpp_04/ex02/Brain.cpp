#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Copy Brain constructor called" << std::endl;
    *this = obj;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(Brain const &obj)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &obj){
        for (int i = 0; i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    }
    return *this;
}