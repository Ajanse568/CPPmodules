#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(std::string name="Defaulty");
    ScavTrap(const ScavTrap& other);
	~ScavTrap();

    void	attack(const std::string& target);
    void	guardGate();
};

#endif