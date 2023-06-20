#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(std::string name="Defaulty");
    FragTrap(const FragTrap& other);
	~FragTrap();

    void	highFivesGuys(void);
};

#endif