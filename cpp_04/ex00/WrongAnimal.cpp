#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Animal")
{
	std::cout << "A wild animal appears." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Animal copied" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal disappeared..." << std::endl;
	
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "Animal assigned" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Animal makes weird noise" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}