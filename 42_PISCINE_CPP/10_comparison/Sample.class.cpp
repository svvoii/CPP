/*
** This program demonstrates the use of comparison.
*/

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(int value) : _privateVariable(value) {

	std::cout << "Constructor called" << std::endl;
	std::cout << "this->_privateVariable: " << this->_privateVariable << std::endl;

	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample::getPrivateVariable(void) const {

	return this->_privateVariable;
}

int	Sample::comparison(Sample *other) const {

	if (this->_privateVariable < other->getPrivateVariable()) {
		return -1;
	}
	else if (this->_privateVariable > other->getPrivateVariable()) {
		return 1;
	}

	return 0;
}

/*
** comparison() is a method that takes a pointer to a Sample object
** as a parameter and returns an int indicating the result of the
** comparison of the private variable of the current object and the
** private variable of the object passed as a parameter.
**
** Reffer to the main.cpp file for more details on the actual use.
*/