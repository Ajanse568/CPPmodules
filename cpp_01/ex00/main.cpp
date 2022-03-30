#include "Zombie.hpp"
 #include <cstdlib>

int		main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Bert");
	zombie->announce();
	zombie->announce();
	zombie->announce();
	zombie->announce();

	delete zombie;
	randomChump("Bob");
	delete zombie;
}