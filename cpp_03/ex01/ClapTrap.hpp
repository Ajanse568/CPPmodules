#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>

class ClapTrap
{
private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:

	ClapTrap(std::string name="Defaulty");
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:

	ClapTrap(std::string name, unsigned int hitp, unsigned int energyp, unsigned int attackd);

	std::string	getName(void);
};

#endif