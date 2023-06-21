/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:59:02 by ajanse        #+#    #+#                 */
/*   Updated: 2023/06/21 17:42:58 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "A wild animal appears." << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copied" << std::endl;
	*this = obj;
}

Animal::~Animal(void)
{
	std::cout << "Animal disappeared..." << std::endl;
}

Animal &Animal::operator=(Animal const &obj)
{
	std::cout << "Animal assigned" << std::endl;
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