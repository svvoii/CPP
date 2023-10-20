/*
** This program demonstrates the use of this.
**
** see also Sample.class.hpp where the Class 
** and its attributes, functions / methods are declared.
*/

#include <iostream>

#include "Sample.class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called" << std::endl;

	/**/
	this->variable = 42;
	std::cout << "this->variable: " << this->variable << std::endl;

	this->function();
	/**/

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
** In this example we are using `this` to access the instance's attributes and methods/functions.
** at the time of the constructor call, the instance is not yet created.
**
** This is not the best practice, there are other ways to use `this` 
** at the time of initialization of the instance.
*/