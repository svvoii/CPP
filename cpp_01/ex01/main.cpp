#include <iostream>
#include <string>
#include "includes/Zombie.class.hpp"

int main()
{
	int			numZombies = 0;
	std::string	hordeName;

	std::cout << "Enter the number of zombies: ";
	std::cin >> numZombies;
	std::cin.ignore(); // !!!
	std::cout << "\tThere will be: [" << numZombies << "] zombies created in the Horde." << std::endl;

	std::cout << "Enter the horde name: ";
	std::getline(std::cin, hordeName);
	std::cout << "\thordeName: [" << hordeName << "]" << std::endl;

	Zombie *zombies = zombieHorde(numZombies, hordeName);

	moarBrainz(zombies, numZombies);

	deleteZombieHorde(zombies);

	return 0;
}

/*
** !!! `std::cin.ignore();` is needed after `std::cin >> ..` because
** `std::cin >> ..` leaves a newline character in the input buffer.
** `std::getline(std::cin, ..)` will read this newline character 
** immediately and return an empty string.
** It will be an unexpected behavior.
**
** Another solution would be to use:
** `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`
** This will discard everything in the input buffer until a newline character
** is found.
*/
