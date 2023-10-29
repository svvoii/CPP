#include "../includes/HumanB.class.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "HumanB [" << this->_name << "] created." << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "HumanB [" << this->_name << "] destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
