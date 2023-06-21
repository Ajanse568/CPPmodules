#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
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

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assigned!" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
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