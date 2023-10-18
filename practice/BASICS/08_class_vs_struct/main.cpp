/*
** Source: 42 Piscine CPP
**
** 08_class_vs_struct
**
** This program demonstrates the difference between 
** classes and structs.
*/

#include <iostream>
#include "Sample.class.hpp"

int		main(void) {

	Sample1		instance1;
	Sample2		instance2;

	instance1.function();
	instance2.function();

	return 0;
}

/*
** This program demonstrates the difference between
** classes and structs.
**
** The main difference between a class and a struct is that
** the members of a `class` are private by default, while
** the members of a `struct` are public by default.
**
** Compile with:
** g++ -Wall -Werror -Wextra -o ClassVsStruct main.cpp Sample.class.cpp
*/
