#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
	DiamondTrap(std::string name="Defaulty");
    DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

    void	whoAmI();
};

#endif