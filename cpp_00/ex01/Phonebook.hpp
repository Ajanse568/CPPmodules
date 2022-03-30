#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class Phonebook {


private:

	Contact contacts[8];
	int		next_c;
	int		amount;

	void	searchHeader(void);
	int		askIndex(void);

public:

	Phonebook();
	~Phonebook();

	void	addContact(void);
	void	searchContact(void);

};

#endif