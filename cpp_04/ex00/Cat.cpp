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

Cat::Cat(void)
{
	std::cout << "A wild cat appears" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj)
{
	std::cout << "You have yourself a CopyCat" << std::endl;
	*this = obj;
}

Cat::~Cat(void)
{
	std::cout << "Cat disappeared..." << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Cat assigned" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says Miauw" << std::endl;
}
