#include "../includes/Zombie.class.hpp"

/*
** This function is declared in Zombie.hpp and defined
** in separate file (here) according to the subject requirements.
**
** It creates a Zombie instance using stack local storage.
** Meaning the Zombie instance will be destroyed when the
** function returns.
*/
void randomChump(std::string name) {
	Zombie zombie;

	zombie.SetName(name);
	zombie.announce();
}
