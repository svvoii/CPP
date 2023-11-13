#include "includes/Zombie.class.hpp"

int main()
{
	std::string name1, name2;

	std::cout << "Enter name for Stack Zombie: ";
	if (!std::getline(std::cin, name1)) {
		std::cerr << "Error: Input stream reached end-of-file (EOF)." << std::endl;
		return 1;
	}

	/* STACK instance */
	randomChump(name1);

	std::cout << "Enter name for Heap Zombie: ";
	if (!std::getline(std::cin, name2)) {
		std::cerr << "Error: Input stream reached end-of-file (EOF)." << std::endl;
		return 1;
	}

	/* HEAP instance */
	Zombie *zombieHeap = newZombie(name2);
	zombieHeap->announce();

	// we need to explicitly delete the object if we created it with `new`
	delete zombieHeap;

	return 0;
}
