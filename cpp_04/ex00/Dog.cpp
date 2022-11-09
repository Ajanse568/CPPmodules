/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:56:44 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 13:49:10 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "A wild dog appears" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Dog::~Dog(void)
{
	std::cout << "Dog disappeared..." << std::endl;
}

Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->type = obj.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog says Bark" << std::endl;
}