#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use like this: ./convert [string]" << std::endl;
		return 1;
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return 0;
}
