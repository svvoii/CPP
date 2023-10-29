#include "../includes/HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << "HumanA [" << this->_name << "] created." << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "HumanA [" << this->_name << "] destroyed." << std::endl;
}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
