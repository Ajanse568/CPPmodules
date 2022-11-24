#ifndef __SCALARCASTER_H__
#define __SCALARCASTER_H__

#include <iostream>

class ScalarCaster
{
public:

	ScalarCaster(const std::string str);
	~ScalarCaster();

	static void	convert(const std::string str);
	static void	castChar(char c);
	static void	castInt(int i);
	static void	castFloat(float f);
	static void	castDouble(double d);

};

#endif