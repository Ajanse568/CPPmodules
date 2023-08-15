/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 15:56:44 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 14:53:56 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain)
{
    std::cout << "It is a dog!" << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj), brain(new Brain(*obj.brain))
{
    std::cout << "Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog disappeared..." << std::endl;
}

Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &obj){
        this->_type = obj.getType();
        this->brain = new Brain(*obj.brain);
    }
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog says Bark" << std::endl;
}