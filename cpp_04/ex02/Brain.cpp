#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(Brain const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}
