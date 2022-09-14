#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_name = name;
	std::cout << "ClapTrap constructed! Name: " << name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_name << " gets destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << " attacks " << target \
		<< ", causing "<< this->_attackDamage << " points of damage!"\
		<< std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " is not able to attack:(" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes " << amount << " damage ";
	if (((int)this->_hitPoints - (int)amount) <= 0)
	{
		std::cout << "and dies!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "and has " << this->_hitPoints << " HitPoints left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << this->_name << " repairs itself by " << amount \
		<< " points and now has " << this->_hitPoints << " HitPoints left." << std::endl;
	}
	else
		std::cout << this->_name << " is not able to repair:(" << std::endl;
}