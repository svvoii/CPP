//#include "ClapTrap.hpp"
//#include "ScavTrap.hpp"
//#include "FragTrap.hpp"
#include "includes/DiamondTrap.hpp"

int main()
{
    ClapTrap clap("Claptrap");
    std::cout << std::endl;

    ScavTrap scav("Scavtrap");
    std::cout << std::endl;

    FragTrap frag("Fragtrap");
    std::cout << std::endl;

    DiamondTrap diamond("Diamondtrap");
    std::cout << std::endl;

    clap.attack("enemy");
    scav.guardGate();
    frag.highFivesGuys();
    diamond.whoAmI();

    std::cout << std::endl;

    clap.takeDamage(10);
    scav.takeDamage(20);
    frag.takeDamage(30);
    diamond.takeDamage(40);
    diamond.whoAmI();

    std::cout << std::endl;

    clap.beRepaired(5);
    scav.beRepaired(10);
    frag.beRepaired(15);
    diamond.beRepaired(20);
    diamond.whoAmI();

    std::cout << std::endl;

    clap.attack("enemy");
    scav.attack("enemy");
    frag.attack("enemy");
    diamond.attack("enemy");
    diamond.whoAmI();

    std::cout << std::endl;

    clap.takeDamage(100);
    scav.takeDamage(100);
    frag.takeDamage(100);
    diamond.takeDamage(100);
    diamond.whoAmI();

    std::cout << std::endl;

    clap.beRepaired(100);
    scav.beRepaired(100);
    frag.beRepaired(100);
    diamond.beRepaired(100);
    diamond.whoAmI();

    std::cout << std::endl;

    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

    return 0;
}
