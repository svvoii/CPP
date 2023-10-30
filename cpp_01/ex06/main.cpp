#include "includes/Harl.class.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		std::cout << "Where <level> is one of the following: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	Harl	harl;
	std::string	level(argv[1]);

	harl.complain(level);

	return 0;
}
