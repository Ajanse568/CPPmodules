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

class Fixed
{
private:
	int					_val;
	static const int	_fract = 8;

public:
	Fixed();
	Fixed( const Fixed &obj );
	Fixed( const int val );
	Fixed( const float val );
	~Fixed();

	// Assignment operator
    Fixed&	operator=( const Fixed &other );

    // Comparison operators
    bool	operator>( Fixed const &other) const;
    bool	operator<( Fixed const &other) const;
    bool	operator>=( Fixed const &other) const;
    bool	operator<=( Fixed const &other) const;
    bool	operator==( Fixed const &other) const;
    bool	operator!=( Fixed const &other) const;

	// Arithmetic operators
    Fixed	operator-( const Fixed &other ) const;
    Fixed	operator+( const Fixed &other ) const;
	Fixed	operator*( const Fixed &other ) const;
	Fixed	operator/( const Fixed &other ) const;

	// Increment and decrement operators
    Fixed	operator++(int);
	Fixed	operator++();
	Fixed	operator--(int);
	Fixed	operator--();

	// Min and max functions
    static Fixed	const &min(Fixed const &a, Fixed const &b);
	static Fixed	const &max(Fixed const &a, Fixed const &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);

	// Getters and setters
    int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif