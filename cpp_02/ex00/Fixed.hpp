/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 15:09:59 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/04 09:19:47 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

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