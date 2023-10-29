#include "includes/Zombie.class.hpp"

int main()
{
	std::string name1, name2;

	std::cout << "Enter name for Stack Zombie: ";
	std::getline(std::cin, name1);

	/* STACK instance */
	randomChump(name1);

	std::cout << "Enter name for Heap Zombie: ";
	std::getline(std::cin, name2);

	/* HEAP instance */
	Zombie *zombieHeap = newZombie(name2);
	zombieHeap->announce();

	delete zombieHeap;

	return 0;
}
