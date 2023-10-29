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
