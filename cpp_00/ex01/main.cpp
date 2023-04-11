/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 15:15:26 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/23 15:23:16 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {

	PhoneBook gouden_gids;

	while(1)
	{
		std::string cmd;
		std::cout << "Give command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			gouden_gids.addContact();
		if (cmd == "SEARCH")
			gouden_gids.searchContact();
		if (cmd == "EXIT" || std::cin.eof())
			break;
	}
	return (0);
}
