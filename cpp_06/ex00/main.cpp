#include "ScalarCaster.hpp"
#include <iostream>
#include <limits>
#include <float.h>

std::string	binString(long i, int bytes)
{
	std::string s = "";

	for (int x = 0; x < bytes * 8; x++)
	{
		if (i & 1)
			s = "1" + s;
		else
			s = "0" + s;
		i = i >> 1;
	}
	return (s);
}


int main()
{
	double d = FLT_MAX + 1.014120475e31;
	float f = static_cast<float>(d);
	
	unsigned long *c = reinterpret_cast<unsigned long *>(&f);
	long	i = *c;
	c = reinterpret_cast<unsigned long *>(&d);
	long	n = *c;

	std::cout << "s    e               m" << std::endl;
	std::cout << binString(i, 4).insert(1, " ").insert(10, " ") << std::endl;
	std::cout << "s      e                              m" << std::endl;
	std::cout << binString(n, 8).insert(1, " ").insert(13, " ") << std::endl;
	std::cout << d << std::endl;
	std::cout << f << std::endl;
}