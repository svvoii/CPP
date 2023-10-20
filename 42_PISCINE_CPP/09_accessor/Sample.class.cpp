/*
** This program demonstrates the use of accessors.
*/

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample() {

	std::cout << "Constructor called" << std::endl;

	this->setPrivateVariable(0);
	std::cout << "this->getPrivateVariable(): " << this->getPrivateVariable() << std::endl;

	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample::getPrivateVariable(void) const {

	return this->_privateVariable;
}

void	Sample::setPrivateVariable(int value) {

	if (value >= 0) {
		this->_privateVariable = value;
	}

	return ;
}

/*
** In our getter, we return the value of the private member.
** see line 26: return this->_privateVariable;
**
** In our setter, we set the value of the private member.
** But there is a condition to prevent the private member from being modified.
** see line 35: if (value >= 0) { this->_privateVariable = value; }
*/