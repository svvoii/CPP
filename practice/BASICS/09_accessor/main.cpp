/*
** Source: 42 Piscine CPP
**
** 09_accessor
**
** This program demonstrates the use of accessors.
*/

#include <iostream>
#include "Sample.class.hpp"

int main(void) {

	Sample instance;

	instance.setPrivateVariable(42);
	std::cout << "instance.getPrivateVariable(): " << instance.getPrivateVariable() << std::endl;
	
	std::cout << "Changing private member ..instance.setPrivateVariable(-42)" << std::endl;
	instance.setPrivateVariable(-42);
	std::cout << "instance.getPrivateVariable(): " << instance.getPrivateVariable() << std::endl;

	return 0;
}

/*
** In this example, we create an instance of Sample Class.
** Then we set the private member to 42.
** Then we print the value of the private member.
** Then we set the private member to -42.
** Then we print the value of the private member.
** But the private member is not modified because of the condition in the mutator/setter.
** see Sample.class.cpp line 35: if (value >= 0) { this->_privateVariable = value; }
**
** Compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o Accessors main.cpp Sample.class.cpp
*/