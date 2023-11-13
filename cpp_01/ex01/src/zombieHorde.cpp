#include "../includes/Zombie.class.hpp"

/*
** Allocates an array of N zombies and sets their names to the given name.
** Returns a pointer to the first zombie in the array.
*/
Zombie *zombieHorde(int N, std::string name) {

	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].SetName(name);
	}

	return zombies;
}

/*
** This function is not part of the exercise.
** It prints the name of the zombieHorde and 
** calls the announce() method for each zombie.
*/
void moarBrainz(Zombie *zombies, int N) {

	for (int i = 0; i < N; i++) {
		std::cout << "Zombie [" << i + 1;
		std::cout << "] from horde [" << zombies[i].getName() << "]... ";
		zombies[i].announce(i + 1);
	}
}

/*
** Deletes the allocated instances of the Zombie class.
*/
void deleteZombieHorde(Zombie *zombies) {

	delete[] zombies;
}

