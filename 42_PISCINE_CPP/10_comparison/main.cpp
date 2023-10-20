/*
** Source: 42 Piscine CPP
**
** 09_accessor
**
** This program demonstrates the use of comparison.
** It illustrates the difference between physical and structural
** comparison.
** Philosophically, two objects are equal if they are the same object
** in memory. This is called physical equality.
**
** Two objects are structurally equal if they have the same value.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main() {

	Sample	instance1(42);
	Sample	instance2(42);

	/* This will always be true, self-comparison 
	it produses compilation error if compiled with flags 
	if (&instance1 == &instance1) {
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	}
	else {
		std::cout << "instance1 and instance1 are not physically equal" << std::endl;
	}
	*/

	if (&instance1 == &instance2) {
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	}
	else {
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;
	}

	if (instance1.comparison(&instance1) == 0) {
		std::cout << "instance1 and instance1 are structurally equal" << std::endl;
	}
	else {
		std::cout << "instance1 and instance1 are not structurally equal" << std::endl;
	}

	if (instance1.comparison(&instance2) == 0) {
		std::cout << "instance1 and instance2 are structurally equal" << std::endl;
	}
	else {
		std::cout << "instance1 and instance2 are not structurally equal" << std::endl;
	}

	return 0;
}


/*
** The first comparison `(instance1 == instance1)` will always be true
** since it is a self-comparison. It throws a compilation error if used with flags.
**
** The second comparison `(instance1 == instance2)` compares two different objects,
** or instances of the Sample class. It will always be differet values, since
** those are two different objects in memory.
**
** The third comparison `(instance1.comparison(&instance1))` compares the private
** variable of the instance1 object with the private variable of the instance1.
** This is the comparisom logic embedded in the Sample class.
** It will always be true, since it compares the value of the same object.
**
** The fourth comparison `(instance1.comparison(&instance2))` compares the private
** variable of the instance1 object with the private variable of the instance2.
**
** Compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o Comparison main.cpp Sample.class.cpp
*/