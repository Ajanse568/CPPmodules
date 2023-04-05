#include "Zombie.hpp"
#include <iostream>

Zombie*		zombieHorde( int N, std::string name )
{
	Zombie	*first;
	
	if ( N <= 0 )
	{
		std::cout << "Give a number above 0. Making a default horde of 5 zombies.\n";
		N = 5;
	}
	first = new Zombie[N]();
	for (int i = 0; i < N; i++)
		first[i].nameZombie(name);
	return (first);
}