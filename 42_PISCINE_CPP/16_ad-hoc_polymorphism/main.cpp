/*
** Source: 42 Piscine CPP
**
** 16_ad-hoc_polymorphism
**
** This program demonstrates the use of 
** ad-hoc polymorphism in C++.
*/
#include "Sample.class.hpp"
#include <iostream>

int main() {
	Sample instance;

	std::cout << "instance.funclion('a'): ";
	instance.function('A');

	std::cout << "instance.function(42): ";
	instance.function(42);

	std::cout << "instance.function(42.42f): ";
	instance.function(42.42f);

	std::cout << "instance.function(instance): ";
	instance.function(instance);

	return 0;
}

/*
** compile with:
** c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o ad-hoc_polymorphism
*/
