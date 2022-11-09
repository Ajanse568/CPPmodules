/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:58:07 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 13:48:46 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "A wild cat appears" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Cat::~Cat(void)
{
	std::cout << "Cat disappeared..." << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->type = obj.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says Miauw" << std::endl;
}
