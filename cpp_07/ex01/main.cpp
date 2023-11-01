#include "iter.hpp"

int	main(void) {

	int		int_array[5] = {1, 2, 3, 4, 5};
	float	float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Here we have 3 arrays:" << std::endl;
	std::cout << "int_array: {1, 2, 3, 4, 5}" << std::endl;
	std::cout << "float_array: {1.1, 2.2, 3.3, 4.4, 5.5}" << std::endl;
	std::cout << "char_array: {'a', 'b', 'c', 'd', 'e'}" << std::endl;
	std::cout << std::endl;

	std::cout << "the output of ::print(int_array) function: [" << std::endl;
	::print(int_array);
	std::cout << "]" << std::endl;

	std::cout << "the output of ::print(float_array) function:" << std::endl;
	::print(float_array);
	std::cout << "]" << std::endl;

	std::cout << "the output of ::print(char_array) function:" << std::endl;
	::print(char_array);
	std::cout << "]" << std::endl;

	std::cout << "Calling `::iter(int_array, 5, ::print)` function:" << std::endl;
	::iter(int_array, 5, ::print);
	std::cout << std::endl;

	std::cout << "Calling `::iter(float_array, 5, ::print)` function:" << std::endl;
	::iter(float_array, 5, ::print);
	std::cout << std::endl;

	std::cout << "Calling `::iter(char_array, 5, ::print)` function:" << std::endl;
	::iter(char_array, 5, ::print);
	std::cout << std::endl;

	return 0;
}
