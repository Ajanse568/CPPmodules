#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << this->_name << " is now a FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " is not a FragTrap anymore." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << "FragTrap copied!" << std::endl;
    *this = other;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        this->_energyPoints--;
        std::cout << this->_name << " puts his hand up in anticipation of a high five..." << std::endl;
    }
    else
        std::cout << this->_name << " is not able to put his hand up :(" << std::endl;
}