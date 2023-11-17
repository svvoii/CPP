
#include "includes/ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap("CL4P-TP");
	std::cout << std::endl;

    ScavTrap scavTrap("SC4V-TP");
	std::cout << std::endl;

	std::cout << MAGENTA << "CLAP-TP (parent class) in action:" << RESET << std::endl;

    clapTrap.attack("ENEMY");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);

	std::cout << std::endl;
	std::cout << MAGENTA << "SCAV-TP (child class) in action:" << RESET << std::endl;

    scavTrap.attack("ENEMY_2");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();
	std::cout << std::endl;

    return 0;
}
