/*
** 11_non_member_attributs_and_non_member_functions
*/

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) : variable(0) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::function(void) const {

	std::cout << "Member function called" << std::endl;
	return ;
}

/*
**
** Reffer to the main.cpp file for more details on the actual use.
*/