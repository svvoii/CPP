#include <iostream>
#include <string>

void	passedByPointer(std::string* str) {
	*str += "Neo...";
}

void	passedByConstPointer(std::string const * str) {
	std::cout << "\t" << *str << std::endl;
}

void	passedByReference(std::string& str) {
	str += " Follow the white rabbit...";
}

void	passedByConstReference(std::string const & str) {
	std::cout << "\t" << str << std::endl;
}

int	main() {

	std::string str = "Wake up ";

	std::cout << "\tstr = " << str << std::endl;

	std::cout << "Passed by pointer: [*str += 'Neo']" << std::endl;
	passedByPointer(&str);
	std::cout << "Passed by const pointer: " << std::endl;
	passedByConstPointer(&str);

	str += " The Matrix has you...";

	std::cout << "Passed by reference: [str += ...]" << std::endl;
	passedByReference(str);
	std::cout << "Passed by const reference: " << std::endl;
	passedByConstReference(str);

	return 0;
}

/*
** We can pass any type of variable to a function by reference.
** The function will be able to modify the value of the variable.
**
** This example shows that we can pass a variable by reference to a function.
** And we can modify the value of the variable in the function.
**
** A reference also can be explained as a non-void constant.
*/
