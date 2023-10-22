#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Sample::Sample(int const n) : _variable(n) {
	std::cout << "Parametric constructor called" << std::endl;
	return;
}

Sample::Sample(Sample const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Sample::~Sample(void) {
	std::cout << "Default Destructor called" << std::endl;
	return;
}

int Sample::getVariable(void) const {
	return this->_variable;
}

Sample & Sample::operator=(Sample const & rhs) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_variable = rhs.getVariable();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Sample const & rhs) {
	o << "The value of _variable is: " << rhs.getVariable();
	return o;
}

/*
** `o` is a reference to the output stream.
*/
