#include "Weapon.hpp"

Weapon::Weapon( std::string new_type)
{
	this->type = new_type;
}

Weapon::Weapon( void )
{
	this->type = "AK-47";
}

Weapon::~Weapon( void )
{
}

const std::string&  Weapon::getType( void )
{
	return(this->type);
}

void    Weapon::setType( std::string new_type)
{
	this->type = new_type;
}
