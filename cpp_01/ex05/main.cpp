#include "includes/Harl.class.hpp"
#include <iostream>

int	main(void) {

	Harl		harl;
	std::string	level;

	while (1) {

		std::cout << "Enter a LEVEL of complaint: ";

		if (!std::getline(std::cin, level)) {
			std::cout << "End of input signal." << std::endl;
			break ;
		}

		if (level == "EXIT") {
			std::cout << "exit." << std::endl;
			break ;
		}
		harl.complain(level);
	}

	return 0;
}

