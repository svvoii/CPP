#include "includes/Harl.class.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << std::endl;
		std::cout << "Error: Invalid number of arguments." << std::endl;
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		std::cout << "Where <level> is one of the following: DEBUG, INFO, WARNING, ERROR" << std::endl;
		std::cout << std::endl;
		return 1;
	}

	Harl		harl;
	std::string	level(argv[1]);

	harl.complain(level);

	return 0;
}
