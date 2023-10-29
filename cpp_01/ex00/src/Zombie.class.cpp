#include "../includes/Zombie.class.hpp"

/*
Zombie::Zombie(void) {
	std::cout << "Zombie created" << std::endl;
}
*/

Zombie::~Zombie(void) {
	std::cout << "Zombie [" << this->getName() << "] destroyed." << std::endl;
}

void Zombie::SetName(std::string name) {
	this->_name = name;
}

std::string &Zombie::getName(void) {
	return this->_name;
}

void Zombie::announce() {
	//std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
Zombie *newZombie(std::string name) {
	Zombie *zombie = new Zombie();

	zombie->SetName(name);

	return zombie;
}

void randomChump(std::string name) {
	Zombie zombie;

	zombie.SetName(name);
	zombie.announce();
}
*/
