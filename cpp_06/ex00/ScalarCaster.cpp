#include "ScalarCaster.hpp"

ScalarCaster::ScalarCaster(const std::string str)
{
	ScalarCaster::convert(str);
}

ScalarCaster::~ScalarCaster()
{
}

void	ScalarCaster::convert(const std::string str)
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