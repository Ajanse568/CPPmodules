#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon {

private:

	std::string	type;

public:

	Weapon( std::string new_type );
	Weapon( void );
	~Weapon( void );

	const std::string&		getType( void );
	void					setType( std::string new_type );

};

#endif