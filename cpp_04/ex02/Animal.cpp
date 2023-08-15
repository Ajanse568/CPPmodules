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

Animal::Animal(): _type("Animal")
{
    std::cout << "A wild animal appears." << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "A wild animal appears." << std::endl;
}

Animal::Animal(const Animal &obj): _type(obj._type)
{
    std::cout << "Copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal disappeared..." << std::endl;
}

Animal &Animal::operator=(Animal const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &obj){
        this->_type = obj.getType();
    }
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes weird noise" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}