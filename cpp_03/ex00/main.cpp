
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Bob");

    clapTrap.attack("dementor");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);
    clapTrap.attack("dementor");

    ClapTrap secondClapTrap("Alice");

    secondClapTrap.attack("enemy");
    secondClapTrap.takeDamage(20);
    secondClapTrap.beRepaired(10);

    ClapTrap thirdClapTrap("Charlie");

    thirdClapTrap.attack("enemy");
    thirdClapTrap.takeDamage(30);
    thirdClapTrap.beRepaired(15);

    return 0;
}
