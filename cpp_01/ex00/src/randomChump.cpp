#include "../includes/Zombie.class.hpp"

/*
** This is the definition of the function from Zombie class.
** It shall be in separate file (here) according to the subject.
**
** `randomChump` creates a Zombie instance using stack local storage.
** Zombie instance will be destroyed when the function returns.
*/
void randomChump(std::string name) {
	Zombie zombie;

	zombie.SetName(name);
	zombie.announce();
}
