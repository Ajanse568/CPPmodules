/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:59:02 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 13:40:33 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "A wild animal appears." << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Animal::~Animal(void)
{
	std::cout << "Animal disappeared..." << std::endl;
}

Animal &Animal::operator=(Animal const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makes weird noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}