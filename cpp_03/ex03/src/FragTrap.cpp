#include "../includes/FragTrap.hpp"

/*
** This constructor overrides the default `ClapTrap` constructor
** with values unique to the `FlagTrap` class.
*/
FragTrap::FragTrap(void) : ClapTrap() {

	this->_name = "<default_FragTrap>";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << CYAN << "\t< FragTrap default constructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

/*
** This constructor overrides the default `ClapTrap` constructor
** with values unique to the `FlagTrap` class.
*/
FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << CYAN << "\t< FragTrap NAME constructor called >" << RESET << " (name: " << name << ")" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << RED << "\t< FragTrap destructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

/*
** `highFivesGuys` method will be unique to the FlagTrap class.
** Calling this method will decrease the energy points of the
** FlagTrap object by 1.
*/
void FragTrap::highFivesGuys(void) {
	
	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
	}

	this->_energyPoints -= 1;
	std::cout << "FragTrap " << this->_name;
	std::cout << " says: \"High five guys!\"";
	std::cout << " (energy points left: " << this->_energyPoints << ")";
	std::cout << std::endl;
}
