#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Animal")
{
	std::cout << "A wild animal appears." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Animal copied" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Animal disappeared..." << std::endl;
	
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "Animal assigned" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Animal makes weird noise" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}