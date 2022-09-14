/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:09:59 by ajanse        #+#    #+#                 */
/*   Updated: 2022/09/14 12:28:35 by ajanse        ########   odam.nl         */
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

	Fixed &operator=( const Fixed &obj );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif