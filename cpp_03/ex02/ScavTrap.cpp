#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << this->_name << " is now a ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " is not a ScavTrap anymore." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    std::cout << "ScavTrap copied!" << std::endl;
    *this = other;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << this->_name << " !smashes! " << target \
        << ", causing "<< this->_attackDamage << " points of damage!"\
        << std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << this->_name << " is not able to attack :(" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        this->_energyPoints--;
        std::cout << this->_name << " has entered in Gate keeper mode." << std::endl;
    }
    else
        std::cout << this->_name << " is not able to guard the gate :(" << std::endl;
}