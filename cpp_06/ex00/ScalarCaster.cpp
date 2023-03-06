 #include <iostream>

std::string	pointCheck()

void	castChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	castInt(int i)
{
	std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	castFloat(float f)
{
	std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	castDouble(double d)
{
	std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	convert(const std::string str)
{
	if (str.length() == 1 && !std::isdigit(*str.c_str()))
		castChar(*str.c_str());
	else if (str.back() == 'f' && (str != "+inf" || str != "-inf"))
		castFloat(std::atof(str.c_str()));
	else if (str.find('.') != std::string::npos)
		castDouble(std::atof(str.c_str()));
	else
		castInt(std::atoi(str.c_str()));
}
