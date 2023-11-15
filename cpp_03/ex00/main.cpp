
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Bob");

    clapTrap.attack("NO ONE");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);
    clapTrap.attack("NO ONE");

    ClapTrap secondClapTrap("Alice");

    secondClapTrap.attack("ENEMY");
    secondClapTrap.takeDamage(20);
    secondClapTrap.beRepaired(10);

    ClapTrap thirdClapTrap("Charlie");

    thirdClapTrap.attack("TERMINATOR X-2000");
    thirdClapTrap.takeDamage(30);
    thirdClapTrap.beRepaired(15);

    return 0;
}
