/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:04:24 by ajanse        #+#    #+#                 */
/*   Updated: 2022/11/23 14:04:33 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char my_toupper(char ch)
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

int	main(int argc, char const **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << my_toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}