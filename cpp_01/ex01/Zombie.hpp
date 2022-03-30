#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {


private:
	
	std::string		name;

public:

	Zombie( std::string give_name );
	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	nameZombie( std::string given_name);
};

Zombie*		zombieHorde( int N, std::string name );

#endif