/*
** 16_ad-hoc_polymorphism
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

void	Sample::function(char const c) const {

	std::cout << "Member function overload with char: [" << c << "]" << std::endl;
	return ;
}

void	Sample::function(int const nbr) const {

	std::cout << "Member function overload with int: [" << nbr << "]" << std::endl;
	return ;
}

void	Sample::function(float const fl) const {

	std::cout << "Member function overload with float: [" << fl << "]" << std::endl;
	return ;
}

void	Sample::function(Sample const & i) const {

	std::cout << "Member function overload with Sample @: [" << &i << "]" << std::endl;
	return ;
}

/*
** Reffer to the main.cpp 
** for more details on the actual use.
*/