/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:56:44 by ajanse        #+#    #+#                 */
/*   Updated: 2023/06/21 17:54:41 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "It is a dog!" << std::endl;
}

Dog::Dog(const Dog &obj)
: Animal(obj)
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog disappeared..." << std::endl;
}

Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Dog assigned" << std::endl;
    if (this != &obj) {
        this->_type = obj.getType();
    }
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog says Bark" << std::endl;
}