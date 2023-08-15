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

Cat::Cat(): Animal("Cat"), brain(new Brain)
{
	std::cout << "It is a cat!" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj), brain(new Brain(*obj.brain))
{
	std::cout << "CopyCat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat disappeared..." << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &obj){
        this->_type = obj.getType();
        this->brain = obj.brain;
    }
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat says Miaow" << std::endl;
}

void    Cat::getBrainAddress() const {
    std::cout << &brain << std::endl;
}