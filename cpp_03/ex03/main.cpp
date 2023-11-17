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

    DiamondTrap diamond;
    std::cout << std::endl;

    DiamondTrap diamond2("Diamondtrap");
    std::cout << std::endl;

	std::cout << MAGENTA << "Calling unique methods of each class:" << RESET << std::endl;
    clap.attack("ENEMY");
    scav.guardGate();
    frag.highFivesGuys();
    diamond.whoAmI();

    std::cout << std::endl;

	std::cout << MAGENTA << "Calling `takeDamage` within each class, and `whoAmI` within `DiamondTrap` class:" << RESET << std::endl;
    clap.takeDamage(10);
    scav.takeDamage(20);
    frag.takeDamage(30);
    diamond.takeDamage(40);
    diamond.whoAmI();

    std::cout << std::endl;

	std::cout << MAGENTA << "Calling `beRepaired` within each class, and `whoAmI` within `DiamondTrap` class:" << RESET << std::endl;
    clap.beRepaired(5);
    scav.beRepaired(10);
    frag.beRepaired(15);
    diamond.beRepaired(20);
    diamond.whoAmI();

    std::cout << std::endl;

	std::cout << MAGENTA << "Calling `attack` within each class, and `whoAmI` within `DiamondTrap` class:" << RESET << std::endl;
    clap.attack("CLP_ENEMY");
    scav.attack("SCV_ENEMY");
    frag.attack("FRG_ENEMY");
    diamond.attack("DIAMOND_ENEMY");
    diamond.whoAmI();

    std::cout << std::endl;

	std::cout << MAGENTA << "Calling `takeDamage` within each class, and `whoAmI` within `DiamondTrap` class:" << RESET << std::endl;
    clap.takeDamage(100);
    scav.takeDamage(100);
    frag.takeDamage(100);
    diamond.takeDamage(100);
    diamond.whoAmI();

    std::cout << std::endl;

	std::cout << MAGENTA << "Calling `beRepaired` within each class, and `whoAmI` within `DiamondTrap` class:" << RESET << std::endl;
    clap.beRepaired(100);
    scav.beRepaired(100);
    frag.beRepaired(100);
    diamond.beRepaired(100);
    diamond.whoAmI();
    std::cout << std::endl;

	std::cout << MAGENTA << "Calling inherited methods by the first `DiamondTrap` class:" << RESET << std::endl;
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
    std::cout << std::endl;

	std::cout << MAGENTA << "Calling inherited methods by the second `DiamondTrap` class:" << RESET << std::endl;
    diamond2.highFivesGuys();
    diamond2.guardGate();
    diamond2.whoAmI();
    std::cout << std::endl;

    return 0;
}
