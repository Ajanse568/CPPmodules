#include "Zombie.hpp"
#include <iostream>

Zombie*		zombieHorde( int N, std::string name )
{
	Zombie	*horde;
	
	if ( N <= 0 )
	{
		std::cout << "Give a number above 0. Making a default horde of 5 zombies.\n";
		N = 5;
	}
	horde = new Zombie[N]();
	for (int i = 0; i < N; i++)
		horde[i].nameZombie(name);
	return (horde);
}
