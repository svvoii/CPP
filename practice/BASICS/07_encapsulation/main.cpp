/*
** Source: 42 Piscine CPP
** 
** 07_encapsulation
** 
** This program demonstrates the use of encapsulation.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main(void) {

	Sample	instance;

	instance.publicVariable = 42;
	std::cout << "instance.publicVariable = " << instance.publicVariable << std::endl;
	// instance._privateVariable = 42; // error: ‘int Sample::_privateVariable’ is private within this context
	// std::cout << "instance._privateVariable = " << instance._privateVariable << std::endl; // error: ‘int Sample::_privateVariable’ is private within this context

	instance.publicFunction();
	// instance._privateFunction(); // error: ‘void Sample::_privateFunction() const’ is private within this context

	return 0;
}

/*
** Commented out the lines illustrste the error messages
** when trying to access private members from outside the class.
**
** The public members are accessible from anywhere.
** While the private members are only accessible from within the class.
** This is encapsulation in its simplest form.
** 
** Compile with:
** g++ -Wall -Werror -Wextra -Wno-useu -o Encapsulation main.cpp Sample.class.cpp
*/
