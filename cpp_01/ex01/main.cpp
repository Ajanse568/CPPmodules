#include "Zombie.hpp"
 #include <cstdlib>

int		main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "Bob");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
}