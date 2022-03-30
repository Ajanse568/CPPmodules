#include "HumanB.hpp"

HumanB::HumanB( std::string given_name )
{
	this->name = given_name;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void )
{
	std::cout << this->name << " attacks with " << this->weapon->getType() << '\n'; 
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}