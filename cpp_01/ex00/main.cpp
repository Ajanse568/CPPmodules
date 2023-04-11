#include "Zombie.hpp"

int		main(void)
{
    Zombie	*zombie;

    zombie = newZombie("Bert");
	zombie->announce();
	zombie->announce();

	randomChump("Bob");
	delete zombie;
}