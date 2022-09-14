/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:10:02 by ajanse        #+#    #+#                 */
/*   Updated: 2022/09/14 12:52:58 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int val)
{
	std::cout << "Copy constructor called" << std::endl;
	this->val = val << Fixed::fract;
}

Fixed::Fixed(const float val)
{
	std::cout << "Copy constructor called" << std::endl;
	this->val = roundf(val * (1 << Fixed::fract));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->val / (float)(1 << Fixed::fract));
}

int	Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
	return (this->val >> Fixed::fract);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}