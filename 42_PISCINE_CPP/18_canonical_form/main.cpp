/*
** Source: 42 Piscine CPP
**
** 18_canonical_form
**
** This program demonstrates the use of 
** the canonical form of a class in C++.
*/
#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample instance1;
	Sample instance2(42);
	Sample instance3(instance1);

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return 0;
}

/*
** `Sample instance3(instance1);` is equivalent to `Sample instance3 = instance1;`
** in this case the copy constructor is called with `instance1` as argument.
**
** `instance3 = instance2;` the assignment operator overload is used here `..operator=(..)`.
**
** compile with:
** c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o canonicalForm
*/
