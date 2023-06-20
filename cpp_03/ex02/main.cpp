#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << std::endl;

    ScavTrap Scavy("Scavy");

    std::cout << std::endl;
    clap_away(Scavy);
    Scavy.guardGate();
    for (int i = 0; i < 50; i++)
        Scavy.guardGate();
    std::cout << std::endl;

    FragTrap Fragy("Fragy");
    std::cout << std::endl;
    clap_away(Fragy);
    Fragy.highFivesGuys();
}