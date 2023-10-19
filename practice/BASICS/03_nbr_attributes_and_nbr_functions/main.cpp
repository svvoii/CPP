/*
** Source: 42 Piscine CPP
**
** 03_nbr_attributes_and_nbr_functions
**
** This program demonstrates the use of 
** number attributes and
** number functions.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main() {
	
	Sample	instance; // instance of the class Sample

	instance.variable = 42; // assign the value 42 to the attribute variable
	std::cout << "instance variable: " << instance.variable << std::endl;

	instance.function(); // call the method/function function()

	return 0;
}

/*
** compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o SampleClassAtrFunc main.cpp Sample.class.cpp
*/
