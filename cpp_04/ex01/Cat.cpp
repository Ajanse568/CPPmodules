/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:58:07 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 15:21:46 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "It is a cat!" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat disappeared..." << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_type = obj.getType();
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat says Miauw" << std::endl;
}

void	Cat::pickBrain(void) const
{
	std::cout << this->brain << std::endl;
}