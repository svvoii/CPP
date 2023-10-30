#include "includes/Harl.class.hpp"

int	main(void) {

	Harl	harl;

	std::string	level;
	while (1) {

		std::cout << "Enter a LEVEL of complaint: ";

		std::getline(std::cin, level);

		if (level == "EXIT") {
			break ;
		}

		harl.complain(level);
	}

	return 0;
}
