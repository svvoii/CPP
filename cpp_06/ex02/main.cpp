/*
** This exccercise illustrates how to identify the type of a variable.
** We are not using `std::type_info` which contains information
** about a type and usually used for that matter.
**
** The idea is to identify the type of a variable on our own.
**
** The main function tests the implementation of the different
** classes `A`, `B`, `C` and `Base` and illustrates the way 
** we can identify the type of a variable.
*/

#include "src/realType.cpp"

int main(void) {

	srand(time(NULL));

	Base *base = generate();

	std::cout << std::endl;
	std::cout << MAGENTA << "Testing with a pointer to `Base`" << RESET << std::endl;
	identify(base);

	std::cout << std::endl;

	std::cout << MAGENTA << "Testing with a reference to `Base`" << RESET << std::endl;
	identify(*base);

	std::cout << std::endl;

	delete base;

	return 0;
}
