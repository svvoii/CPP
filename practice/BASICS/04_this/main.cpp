/*
** Source: 42 Piscine CPP
**
** 04_this
**
** This program demonstrates the use of this.
*/

#include <iostream>

#include "Sample.class.hpp"

int	main() {
	
	Sample	instance;

	return 0;
}

/*
** Here, when we create an instance of the class Sample, 
** inside the constructor definition we use `this` 
** to access the instance's attributes and methods/functions.
**
** compile with:
** g++ -Wall -Werror -Wextra -Wno-useu -o This main.cpp Sample.class.cpp
*/
