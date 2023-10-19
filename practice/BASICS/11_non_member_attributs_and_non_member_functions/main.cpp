/*
** Source: 42 Piscine CPP
**
** 11_non_member_attributs_and_non_member_functions
**
** This program demonstrates the use of 
** non-member attributes and non-member functions.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main(void) {

	Sample	instance1;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	Sample	instance2;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	Sample	instance3;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	return 0;
}

/*
** In C++, non-member attributes and non-member functions are not part of the class.
** But they are still part of the program.
** Non-member attributes are declared with the `static` keyword, and
** is declared outside of the class definition.
** See the Sample.class.hpp file for more details on how to declare a non-member attribute.
** 
** Non-member attributes can be accessed by all instances of the class, and 
** can be used ti store information that is not specific to any instance of a class.
**
** Compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o NonMember main.cpp Sample.class.cpp
*/