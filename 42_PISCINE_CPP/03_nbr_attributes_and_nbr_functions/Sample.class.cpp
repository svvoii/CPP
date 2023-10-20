/*
** This program demonstrates the use of classes and instances.

** see also Sample.class.hpp where the Class 
** and its attributes, functions / methods are declared.
*/

#include <iostream>

#include "Sample.class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::function(void) {

	std::cout << "Member function called" << std::endl;
	return ;
}

/*
** When we declare a method/function in the `.class.hpp` file,
** we can use a pointer used as an argument to this 
** method/function.
** (see next example in 04_this)
*/