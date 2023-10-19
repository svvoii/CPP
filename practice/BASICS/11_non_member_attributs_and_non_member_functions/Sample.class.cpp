/*
** 11_non_member_attributs_and_non_member_functions
*/

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample() {

	std::cout << "Constructor called";
	Sample::_nbInst += 1;
	std::cout << "\tNumber of instances +1" << std::endl;

	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called";
	Sample::_nbInst -= 1;
	std::cout << "\tNumber of instances -1" << std::endl;
	return ;
}

int	Sample::getNbInst(void) {

	return Sample::_nbInst;
}

int	Sample::_nbInst = 0;

/*
** The following syntax is used to initialize a non-member attribute.
** `int	Sample::_nbInst = 0;` this is the only place where the non-member attribute
** is declared.
** It is initialized in any case, even if the class is never used/instanciated. 
**
** In our constructor, we increment the non-member attribute by 1.
** In our destructor, we decrement the non-member attribute by 1.
**
** The getNbInst() function is a non-member function which simply returns the value.
**
** Reffer to the main.cpp file for more details on the actual use.
*/