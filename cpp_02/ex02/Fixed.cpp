/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:10:02 by ajanse        #+#    #+#                 */
/*   Updated: 2022/09/14 15:19:26 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int val)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->val = val << Fixed::fract;
}

Fixed::Fixed(const float val)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->val = roundf(val * (1 << Fixed::fract));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->val = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator>( Fixed const &other) const
{
	return(this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<( Fixed const &other) const
{
	return(this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=( Fixed const &other ) const
{
	return(this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=( Fixed const &other) const
{
	return(this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator==( Fixed const &other) const
{
	return(this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( Fixed const &other) const
{
	return(this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator-( const Fixed &other )
{
	Fixed	result;

	result.val = this->getRawBits() - other.getRawBits();
	return (result);
}

Fixed Fixed::operator+( const Fixed &other )
{
	Fixed	result;

	result.val = this->getRawBits() + other.getRawBits();
	return (result);
}

Fixed Fixed::operator*( const Fixed &other )
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)this->getRawBits();
	b = (long)other.getRawBits();

	result.setRawBits((a * b) / (1 << Fixed::fract));
	return (result);
}

Fixed Fixed::operator/( const Fixed &other )
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)this->getRawBits();
	b = (long)other.getRawBits();

	result.setRawBits((a * (1 << Fixed::fract)) / b);
	return (result);
}

Fixed Fixed::operator++(int)
{
	Fixed	result(*this);

	++*this;
	return (result);
}

Fixed Fixed::operator++()
{
	this->val++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	result(*this);

	--*this;
	return (result);
}

Fixed Fixed::operator--()
{
	this->val--;
	return (*this);
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}


int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->val / (float)(1 << Fixed::fract));
}

int	Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
	return (this->val >> Fixed::fract);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}