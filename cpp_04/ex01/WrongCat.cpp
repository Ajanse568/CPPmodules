#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "It is a cat!" << std::endl;
	this->_type = "Cat";
    this->brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "Cat disappeared..." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_type = obj.getType();
    this->brain = obj.brain;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Cat says Miauw" << std::endl;
}

void     WrongCat::getBrainAddress() const {
    std::cout << this->brain << std::endl;
}
