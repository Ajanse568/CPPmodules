#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    std::cout << this->_name << " is now a DiamondTrap" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " is not a DiamondTrap anymore." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copied!" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        this->_energyPoints--;
        std::cout << this->_name << " and " << ClapTrap::_name << std::endl;
        std::cout << "energy points: " << this->_energyPoints << std::endl;
        std::cout << "hit points: " << this->_hitPoints << std::endl;
        std::cout << "attack damage: " << this->_attackDamage << std::endl;
    }
    else
        std::cout << this->_name << " is not able to shout his names :(" << std::endl;
}