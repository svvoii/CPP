// Adding Some color to the output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include "iter.hpp"

int	main(void) {

	int		int_array[5] = {1, 2, 3, 4, 5};
	float	float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << MAGENTA << "Here we have 3 basic arrays:" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "int_array: {1, 2, 3, 4, 5}" << RESET << std::endl;
	std::cout << BLUE << "float_array: {1.1, 2.2, 3.3, 4.4, 5.5}" << RESET << std::endl;
	std::cout << GREEN << "char_array: {'a', 'b', 'c', 'd', 'e'}" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "Calling `::print(int_array)` function in a loop: " << RESET << std::endl;
	std::cout << "[";
	for (size_t i = 0; i < 5; i++) {
		::print(int_array[i]);
	}
	std::cout << "]" << std::endl << std::endl;

	std::cout << BLUE << "Calling `::print(float_array)` function in a loop:" << RESET << std::endl;
	std::cout << "[";
	for (size_t i = 0; i < 5; i++) {
		::print(float_array[i]);
		std::cout << " ";
	}
	std::cout << "]" << std::endl << std::endl;

	std::cout << GREEN << "Calling `::print(char_array)' function in a loop:" << RESET << std::endl;
	std::cout << "[";
	for (size_t i = 0; i < 5; i++) {
		::print(char_array[i]);
	}
	std::cout << "]" << std::endl << std::endl;

	std::cout << CYAN << "Calling `::iter(int_array, 5, ::print)` function:" << RESET << std::endl;
	std::cout << "[";
	::iter(int_array, 5, ::print);
	std::cout << "]" << std::endl << std::endl;

	std::cout << BLUE << "Calling `::iter(float_array, 5, ::print)` function:" << RESET << std::endl;
	std::cout << "[";
	::iter(float_array, 5, ::print);
	std::cout << "]" << std::endl << std::endl;

	std::cout << GREEN << "Calling `::iter(char_array, 5, ::print)` function:" << RESET << std::endl;
	std::cout << "[";
	::iter(char_array, 5, ::print);
	std::cout << "]" << std::endl << std::endl;

	return 0;
}
