/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 15:15:22 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/23 15:15:23 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>

class Contact {

private:

	static std::string	field_names[5];
	std::string			field_values[5];

public:

	Contact();
	~Contact();

	void	setInfo(void);
	void	preview(void);
	void	fullview(void);

};

#endif