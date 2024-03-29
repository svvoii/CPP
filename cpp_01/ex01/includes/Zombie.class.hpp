/*
** In this exercise, we use same class created in cpp_01/ex00.
** The only difference is that we create an array of zombies,
** so, we need another function for that.
** As well as a function to delete the array of zombies.
**
** We also added `announce(int index)` as an option.
** It prints the zombie name and its index.
*/
#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		~Zombie(void);

		void SetName(std::string name);
		void announce(void);
		void announce(int index);
		std::string &getName(void);
};

Zombie *zombieHorde(int N, std::string name);
void moarBrainz(Zombie *zombies, int N);
void deleteZombieHorde(Zombie *zombies);

#endif
