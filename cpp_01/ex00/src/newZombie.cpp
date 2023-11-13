#include "../includes/Zombie.class.hpp"

/*
** This is the definition of the function from Zombie class.
** It shall be in separate file (here) according to the subject.
**
** It creates an instance of Zombie class on the heap and returns
** a pointer to it.
*/
Zombie *newZombie(std::string name) {
	Zombie *zombie = new Zombie();

	zombie->SetName(name);

	return zombie;
}
