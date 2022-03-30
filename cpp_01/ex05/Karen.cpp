#include "Karen.hpp"

Karen::Karen(void) 
{
	this->functptr[0] = &debug;
	this->functptr[1] = &info;
	this->functptr[2] = &warning;
	this->functptr[3] = &error;
}

Karen::~Karen(void)
{
}

void	Karen::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Karen::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->levels[i])
		{
			std::cout << level;
			(*functptr[i])();
		}
	}
}