#include "../includes/Zombie.class.hpp"

/*
** This function is declared in Zombie.hpp and defined 
** in separate file (here) according to the subject requirements.
** It creates a Zombie instance on the heap and returns
** a pointer to it.
*/
Zombie *newZombie(std::string name) {
	Zombie *zombie = new Zombie();

	zombie->SetName(name);

	return zombie;
}
