#include "../includes/Zombie.class.hpp"

Zombie::~Zombie(void) {
	std::cout << "Zombie from horde [" << this->getName() << "] destroyed." << std::endl;
}

void Zombie::SetName(std::string name) {
	this->_name = name;
}

std::string &Zombie::getName(void) {
	return this->_name;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::announce(int index) {
	std::cout << this->_name << "[" << index << "]: BraiiiiiiinnnzzzZ..." << std::endl;
}
