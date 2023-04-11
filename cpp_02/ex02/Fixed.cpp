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
#include <cmath>

Fixed::Fixed()
{
	this->_val = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	*this = obj;
}

Fixed::Fixed(const int val)
{
    this->_val = val << Fixed::_fract;
}

Fixed::Fixed(const float val)
{
	this->_val = roundf(val * (1 << Fixed::_fract));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &obj)
{
    this->_val = obj.getRawBits();
	return (*this);
}

//--------------------Comparison operators--------------------
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

//--------------------Arithmetic operators--------------------
Fixed Fixed::operator-( const Fixed &other ) const
{
	Fixed	result;

	result._val = this->getRawBits() - other.getRawBits();
	return (result);
}

Fixed Fixed::operator+( const Fixed &other ) const
{
	Fixed	result;

	result._val = this->getRawBits() + other.getRawBits();
	return (result);
}

Fixed Fixed::operator*( const Fixed &other )const
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)this->getRawBits();
	b = (long)other.getRawBits();

	result.setRawBits((a * b) / (1 << Fixed::_fract));
	return (result);
}

Fixed Fixed::operator/( const Fixed &other ) const
{
	Fixed	result;
	long	a;
	long	b;

	a = (long)this->getRawBits();
	b = (long)other.getRawBits();

	result.setRawBits((a * (1 << Fixed::_fract)) / b);
	return (result);
}

//--------------------Increment/Decrement operators--------------------
Fixed Fixed::operator++(int)
{
	Fixed	result(*this);

	++*this;
	return (result);
}

Fixed Fixed::operator++()
{
	this->_val++;
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
	this->_val--;
	return (*this);
}

//--------------------Min/Max--------------------
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

//--------------------Getters/Setters--------------------
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float	Fixed::toFloat(void) const
{
	return((float)this->_val / (float)(1 << Fixed::_fract));
}

int	Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
	return (this->_val >> Fixed::_fract);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}