#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_energyPoints = 50;
    std::cout << this->_name << " is now a ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " is not a ScavTrap anymore." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap assigned!" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
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