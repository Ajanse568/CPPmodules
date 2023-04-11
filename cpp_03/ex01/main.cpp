#include "ScavTrap.hpp"

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
    ClapTrap Clapy("Clapy");

    std::cout << std::endl;
    clap_away(Clapy);
//    Clapy.beRepaired(10);
//    Clapy.takeDamage(10);
//    Clapy.attack("Scavy");
//   Clapy.guardGate();

    std::cout << std::endl;

    ScavTrap Scavy("Scavy");

    std::cout << std::endl;
    clap_away(Scavy);
    Scavy.guardGate();
    for (int i = 0; i < 46; i++)
        Scavy.guardGate();
    std::cout << std::endl;
}