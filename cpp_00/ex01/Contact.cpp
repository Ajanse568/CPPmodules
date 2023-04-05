/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 15:15:18 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/23 15:15:20 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

std::string	Contact::field_names[5] = {
	"first_name",
	"last_name",
	"nickname",
	"phone_number",
	"darkest_secret"};

void	Contact::setInfo(void) {

	for (int i = 0; i < 5; i++)
	{
		std::cout << field_names[i] << ": ";
		std::getline(std::cin, field_values[i]);
		if (field_values[i] == "")
		{
			std::cout << "No empty fields allowed!\n";
			i--;
		}
		if (std::cin.eof())
			break ;
	}

}

void	Contact::preview(void) {

	std::string	output;

	for (int i = 0; i < 3; i++)
	{
		std::cout << std::setw(10);
		output = this->field_values[i];
		if (output.length() > 10)
		{
			output.resize(9);
			output += '.';
		}
		if (i < 2)
			std::cout << output << '|';
		else
			std::cout << output << '\n';
	}
}

void	Contact::fullView(void) {

	for (int i = 0; i < 5; i++)
		std::cout << field_names[i] << ": " << field_values[i] << '\n';
}