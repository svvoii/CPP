#include "ClapTrap.hpp"

/*
** Setting default values for class attributes in the 
** default constructor.
** `_name` is set to "ClapTrap" by default.
** `_hitPoints` is the amount of hit points the ClapTrap
** has. It represents the health level of the ClapTrap.
** `_energyPoints` is the amount of energy points the ClapTrap has.
** `_attackDamage` is the amount of damage the ClapTrap can deal.
*/
ClapTrap::ClapTrap(void) : 
	_name("ClapTrap"), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) {

	std::cout << CYAN << "\t< ClapTrap default constructor called >" << RESET << std::endl;
}

/*
** Another constructor that takes a string as an argument
** and sets the name attribute to that string. All other
** attributes are set to default values.
*/
ClapTrap::ClapTrap(std::string name) : 
	_name(name), 
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0) {

	std::cout << CYAN << "\t< ClapTrap NAME constructor called >" << RESET << std::endl;
}

/*
** Copy constructor that takes a reference to a ClapTrap object
** as an argument and copies all the attributes of that object
** to the new object.
*/
ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << CYAN << "\t< ClapTrap copy constructor called >" << RESET << std::endl;

	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
}

ClapTrap::~ClapTrap(void) {
	std::cout << RED << "\t< ClapTrap destructor called >" << RESET << std::endl;
}

/*
** Overloading the assignment operator to make a deep copy
** of the ClapTrap object.
** Deep copy is needed because the default assignment operator
** only copies the values of the attributes of the object,
** but not the values.
*/
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	std::cout << CYAN << "\t< ClapTrap assignment operator called >" << RESET << std::endl;

	if (this == &clapTrap) {
		return *this;
	}
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;

	return *this;
}

/*
** `attack` method that takes a reference to a string as an argument
** as `target` to attack. 
** If the `energyPoints` attribute is 0, the method returns without
** doing anything.
*/
void ClapTrap::attack(std::string const &target) {

	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!";
	std::cout << " (energy points left: " << this->_energyPoints << ")";
	std::cout << std::endl;
}

/*
** `takeDamage` method that takes an unsigned int as an argument
** as `amount` of damage to take.
** If the `hitPoints` attribute is equal to 0, the special message
** is printed.
*/
void ClapTrap::takeDamage(unsigned int amount) {

	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
	} 
	else {
		this->_hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << " takes " << amount;
	std::cout << " points of damage!" << std::endl;

	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is no longer with us.. :(" << std::endl;
	}
}

/*
** `beRepaired` method that takes an unsigned int as an argument
** as `amount` of hit points to repair.
** If the `energyPoints` attribute is equal to 0, the special
** message is printed and method returns without doing anything.
*/
void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
	}

	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name;
	std::cout << " is repaired for " << amount;
	std::cout << " points of damage!";
	std::cout << " (energy points left: " << this->_energyPoints << ")";
	std::cout << std::endl;
}
