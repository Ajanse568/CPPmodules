/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:09:59 by ajanse        #+#    #+#                 */
/*   Updated: 2022/09/14 15:18:04 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Fixed_H__
#define __Fixed_H__

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					val;
	static const int	fract = 8;

public:
	Fixed();
	Fixed( const Fixed &obj );
	Fixed( const int val );
	Fixed( const float val );
	~Fixed();

	Fixed&	operator=( const Fixed &other );

	bool	operator>( Fixed const &other) const;
	bool	operator<( Fixed const &other) const;
	bool	operator>=( Fixed const &other) const;
	bool	operator<=( Fixed const &other) const;
	bool	operator==( Fixed const &other) const;
	bool	operator!=( Fixed const &other) const;

	Fixed	operator-( const Fixed &other );
	Fixed	operator+( const Fixed &other );
	Fixed	operator*( const Fixed &other );
	Fixed	operator/( const Fixed &other );

	Fixed	operator++(int);
	Fixed	operator++();
	Fixed	operator--(int);
	Fixed	operator--();

	static Fixed	const &min(Fixed const &a, Fixed const &b);
	static Fixed	const &max(Fixed const &a, Fixed const &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif