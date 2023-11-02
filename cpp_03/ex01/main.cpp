
#include "includes/ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("CL4P-TP");
    ScavTrap scavTrap("SC4V-TP");

    clapTrap.attack("Handsome Jack");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);

    scavTrap.attack("Handsome Jack");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();

    return 0;
}
