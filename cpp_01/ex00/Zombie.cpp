#include "Zombie.hpp"

Zombie::Zombie ( std::string given_name ) 
{
	this->name = given_name;
}

Zombie::~Zombie ( void )
{
	std::cout << this->name << " sadly just died :(\n";
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}