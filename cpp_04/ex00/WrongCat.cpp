#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "A wild cat appears" << std::endl;
	this->_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "You have yourself a CopyCat" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Cat disappeared..." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &obj)
{
	std::cout << "Cat assigned" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Cat says Miauw" << std::endl;
}