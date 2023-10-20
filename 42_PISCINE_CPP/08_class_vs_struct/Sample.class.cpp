#include <iostream>
#include "Sample.class.hpp"

/*
** This is the example of class Sample declaration
*/

Sample1::Sample1(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample1::~Sample1(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample1::function(void) const {

	std::cout << "Member function called" << std::endl;
	return ;
}

/************************************************************/
/*
** This is the example of a struct Sample declaration
*/

Sample2::Sample2(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample2::~Sample2(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample2::function(void) const {

	std::cout << "Member function called" << std::endl;
	return ;
}

/*
** Declaratio and initalization of both Class and Struct
** can be the same.
*/