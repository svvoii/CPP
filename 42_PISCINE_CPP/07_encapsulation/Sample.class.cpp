/*
** This program demonstrates the use of encapsulation.
*/

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample() {

	std::cout << "Constructor called" << std::endl;

	this->publicVariable = 0;
	std::cout << "this->publicVariable = " << this->publicVariable << std::endl;

	this->_privateVariable = 0;
	std::cout << "this->_privateVariable = " << this->_privateVariable << std::endl;

	this->publicFunction();
	this->_privateFunction();

	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::publicFunction(void) const {

	std::cout << "Member function called" << std::endl;
	return ;
}

void	Sample::_privateFunction(void) const {

	std::cout << "Member function called" << std::endl;
	return ;
}

/*
** Initialize the public and private variables in the same manner.
*/