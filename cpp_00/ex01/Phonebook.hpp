/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 15:15:39 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/23 15:24:08 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {

private:

	Contact contacts[8];
	int		next_c;
	int		amount;

	void	searchHeader(void);
	int		askIndex(void);

public:

	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	searchContact(void);

};

#endif