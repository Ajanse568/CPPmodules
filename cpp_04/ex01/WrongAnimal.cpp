#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "A wild animal appears." << std::endl;
	this->_type = "Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal disappeared..." << std::endl;
	
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
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