#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>

class Brain
{
public:

	Brain();
	Brain( const Brain &obj );
	~Brain();

	Brain &operator=( const Brain &obj );

	std::string	ideas[100];

};

#endif