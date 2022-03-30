#include "Phonebook.hpp"

int main(void) {

	Phonebook gouden_gids;

	while(1)
	{
		std::string cmd;
		std::cout << "Give command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			gouden_gids.addContact();
		if (cmd == "SEARCH")
			gouden_gids.searchContact();
		if (cmd == "EXIT")
			break;
	}
	return (0);
}