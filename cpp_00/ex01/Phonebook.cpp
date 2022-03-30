#include "Phonebook.hpp"

Phonebook::Phonebook() {
	next_c = 0;
	amount = 0;
}

Phonebook::~Phonebook() {
}

void	Phonebook::addContact(void) {

	contacts[next_c].setInfo();
	if (amount != 8)
		amount++;
	next_c++;
	if (next_c == 8)
		next_c = 0;

}

void	Phonebook::searchHeader(void) {

	std::cout << '\n' << "    Index |First Name| Last Name| Nickname " << "\n\n";
	for (int i = 0; i < amount; i++)
	{
		std::cout << std::setw(10) << i << '|';
		contacts[i].preview();
	}
}

int	Phonebook::askIndex(void) {

	int	index = -1;

	while ((index < 0 || index > this->amount - 1) && this->amount > 0)
	{
		std::cout << '\n' << "Give the index of the contact you want to see: ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << '\n' << "Please type a number!" << '\n';
			index = -1;
		}
		else if ((index < 0 || index > this->amount - 1))
			std::cout << '\n' << "Choose an index between 0 and " << this->amount - 1 << '\n';
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (index);
}

void	Phonebook::searchContact(void) {

	int	index;

	if (this->amount == 0)
		std::cout << "No contacts to search yet." << '\n';
	else
	{
		this->searchHeader();
		index = this->askIndex();
		this->contacts[index].fullview();
	}
}