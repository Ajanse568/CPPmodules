#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>

class ClapTrap
{
protected:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
    ClapTrap(std::string name="Defaulty");
    ClapTrap(const std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& other);

    virtual void	attack(const std::string& target);
    void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif