F#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "iostream"
#include "Weapon.hpp"

class HumanB
{
private:

	std::string	name;
	Weapon		*weapon;

public:

	HumanB( std::string given_name );
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif