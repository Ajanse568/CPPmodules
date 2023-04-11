#include "Zombie.hpp"

void	randomChump ( std::string name )
{
	Zombie	walker(name);

    walker.announce();
}