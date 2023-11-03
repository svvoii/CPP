/*
** `DiamondTrap` shall inherit from `ScavTrap` and `FragTrap`.
**
** Class atributtes will be picked from either of its parents
** `ScavTrap` or `FragTrap`:
** - Name, which is passed as argument to the constructor, will be
** ClapTrap::name (parameter ofthe constructor + `_clap_name`).
** - Hit points will be FragTrap::hit_points.
** - Energy points will be ScavTrap::energy_points.
** - Attack damage will be FragTrap::attack_damage.
** - `atack` method will be from `ScavTrap`. 
** - `DiamondTrap` will have its own method: `whoAmI` - it will 
** display both `DiamondTrap`'s name and `ClapTrap`'s name.
**
** The following relationships of all 4 classes illustrates 
** the Dimond problem where `DiamondTrap` inherits from both
** `ScavTrap` and `FragTrap`, when both `ScavTrap` and `FragTrap`
** inherit from `ClapTrap`.
** So, In order to avoid double inheritance of `ClapTrap` class
** by `DiamondTrap`, `ScavTrap` and `FragTrap` must inherit from
** `ClapTrap` as virtually.
** Respective keyword `virtual` was added to the declaration statement
** of `ScavTrap` and `FragTrap` classes in their respective `.hpp` files.
**
** This way the `DiamondTrap` class will have only one instance of
** `ClapTrap` class.
*/

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {

    this->_name = ClapTrap::_name + "_clap_name";
    ClapTrap::_name = "ClapTrap";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;

	std::cout << CYAN << "\t< DiamondTrap default constructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {

    this->_name = ClapTrap::_name + "_clap_name";
    ClapTrap::_name = "ClapTrap";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;

	std::cout << CYAN << "\t< DiamondTrap NAME constructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap) {
	std::cout << CYAN << "\t< DiamondTrap copy constructor called >" << RESET << std::endl;

    this->_name = diamondTrap._name;
    this->_hitPoints = diamondTrap._hitPoints;
    this->_energyPoints = diamondTrap._energyPoints;
    this->_attackDamage = diamondTrap._attackDamage;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << RED << "\t< DiamondTrap destructor called >" << RESET << " (name: " << this->_name << ")" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	std::cout << CYAN << "\t< DiamondTrap assignment operator called >" << RESET << std::endl;

    if (this != &diamondTrap) {
        this->_name = diamondTrap._name;
        this->_hitPoints = diamondTrap._hitPoints;
        this->_energyPoints = diamondTrap._energyPoints;
        this->_attackDamage = diamondTrap._attackDamage;
    }
    return (*this);
}

void DiamondTrap::attack(std::string const &target) {
    //ScavTrap::attack(target);
	if (this->_energyPoints == 0) {
		std::cout << "DiamondTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;

	std::cout << "DiamondTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!";
	std::cout << " (energy points left: " << this->_energyPoints << ")";
	std::cout << std::endl;
}

void DiamondTrap::whoAmI(void) {

	if (this->_energyPoints == 0) {
		std::cout << "DiamondTrap " << this->_name;
		std::cout << " is out of energy!!!" << std::endl;
		return ;
    }

	this->_energyPoints -= 1;
    std::cout << "I AM (" << this->_name;
    std::cout << ")!! THE SON OF (" << ClapTrap::_name << ")!";
    std::cout << std::endl;
}
