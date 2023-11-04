#include "../includes/ScavTrap.hpp"

/*
** This constructor overrides the default `ClapTrap` constructor 
** with values unique to the `ScavTrap` class.
*/
ScavTrap::ScavTrap(void) : ClapTrap() {

	this->_name = "<default_ScavTrap>";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << CYAN << "\t< ScavTrap default constructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

/*
** This constructor overrides the default `ClapTrap` constructor 
** with values unique to the `ScavTrap` class.
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << CYAN << "\t< ScavTrap NAME constructor called >" << RESET << " (name: " << name << ")" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << RED << "\t< ScavTrap destructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

/*
** `attack` method will be overriden to show that the ScavTrap
** is a different robot with its own individuality.
*/
void ScavTrap::attack(std::string const &target) {
	
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;

	std::cout << "ScavTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!";
	std::cout << " (energy points left: " << this->_energyPoints << ")";
	std::cout << std::endl;
}

/*
** `guardGate` method will be unique to the ScavTrap class.
*/
void ScavTrap::guardGate(void) {

	std::cout << "ScavTrap " << this->_name;
	std::cout << " enabled The GATE KEEPER mode !##!" << std::endl;
}
