/*
** This program demonstrates the use of classes and instances.
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

/*
** Here we use '::' the same (scope resolution operator)
** to initialize (consuct) the class and access its constructor.
** 
** `return` is used to indicate that the function has finished.
** It is not necessary to use it in void functions, but it is
** a good practice to use it. It is more discritive.
*/