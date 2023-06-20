#include "DiamondTrap.hpp"

void    clap_away(ClapTrap& Clap)
{
    Clap.attack("Bert");
    Clap.takeDamage(5);
    Clap.beRepaired(6);
    Clap.takeDamage(12);
    Clap.beRepaired(5);
    Clap.attack("Ernie");
    Clap.takeDamage(50);
    Clap.attack("Bert");
}
int main(void)
{

    DiamondTrap Diamondy("Diamondy");
    std::cout << std::endl;
    DiamondTrap Diamondy2(Diamondy);
    std::cout << std::endl;
    DiamondTrap Diamondy3("Diamondy3");

    std::cout << std::endl;
    Diamondy3 = Diamondy2;
    std::cout << std::endl;

    std::cout << std::endl;
    clap_away(Diamondy);
    Diamondy.ScavTrap::attack("Bert");
    Diamondy.highFivesGuys();
    Diamondy.guardGate();
    Diamondy.whoAmI();
    Diamondy2.whoAmI();
    Diamondy3.whoAmI();
    std::cout << std::endl;
    std::cout << std::endl;
    return (0);
}