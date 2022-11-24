#include <iostream>

int	main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string		*stringPTR = &str;
	std::string&	stringREF = str;

	*stringPTR += "SS";
	std::cout << "Addres: str - " << &str << '\n'
			  << "Addres: stringPTR - " << stringPTR << '\n'
			  << "Addres: stringREF - " << &stringREF << '\n'
			  << "Value: str - " << str << '\n'
			  << "Value: stringPTR - " << *stringPTR << '\n'
			  << "Value: stringREF - " << stringREF << '\n';
}