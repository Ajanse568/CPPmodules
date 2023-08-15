/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:58:07 by ajanse        #+#    #+#                 */
/*   Updated: 2023/06/21 17:45:49 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "It is a cat!" << std::endl;
}

Cat::Cat(const Cat &obj)
: Animal(obj)
{
	std::cout << "You have yourself a CopyCat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat disappeared..." << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Cat assigned" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat says Miauw" << std::endl;
}
