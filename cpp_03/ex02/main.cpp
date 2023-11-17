//#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"

int main()
{
    ClapTrap clap("Claptrap");
	std::cout << std::endl;
    ScavTrap scav("Scavtrap");
    FragTrap frag("Fragtrap");

	std::cout << MAGENTA << "CLAP-TP (parent class) in action:" << RESET << std::endl;
    clap.attack("enemy");
    clap.takeDamage(10);
    clap.beRepaired(5);
	std::cout << std::endl;

	std::cout << MAGENTA << "SCAV-TP (child class) in action:" << RESET << std::endl;
    scav.attack("enemy");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();
	std::cout << std::endl;

	std::cout << MAGENTA << "FRAG-TP (child class) in action:" << RESET << std::endl;
    frag.attack("enemy");
    frag.takeDamage(10);
    frag.beRepaired(5);
    frag.highFivesGuys();
	std::cout << std::endl;

    return 0;
}
