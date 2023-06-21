#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Clap("Clap");
	ClapTrap	Palc("Palc");
	ClapTrap	Defaulty;

	Clap.attack("Bert");
	Clap.takeDamage(5);
	Clap.beRepaired(6);
	Clap.takeDamage(12);
	Clap.beRepaired(5);
	Clap.attack("Ernie");
	for (int i = 0; i < 11; i++)
		Palc.attack("Claps body");
	Palc.takeDamage(5);
	Palc.beRepaired(6);
}