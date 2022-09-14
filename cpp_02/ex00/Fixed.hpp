/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:09:59 by ajanse        #+#    #+#                 */
/*   Updated: 2022/06/10 15:11:54 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Fixed_H__
#define __Fixed_H__

#include <iostream>

class Fixed
{
private:
	int					val;
	static const int	BITS = 8;

public:
	Fixed();
	Fixed( const Fixed &obj );
	~Fixed();

	Fixed &operator=( const Fixed &obj );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif