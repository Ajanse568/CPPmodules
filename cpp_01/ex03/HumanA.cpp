#include "HumanA.hpp"

HumanA::HumanA( std::string given_name, Weapon &weapon)
{
	this->name = given_name;
	this->weapon = &weapon;
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with " << this->weapon->getType() << '\n'; 
}