#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << name << " is now a ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " is not a ScavTrap anymore." << std::endl;
}