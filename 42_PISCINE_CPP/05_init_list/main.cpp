/*
** Source: 42 Piscine CPP
**
** 05_init_list
**
** This program demonstrates the use of initializer lists.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main(void) {

	Sample1	instance1('a', 42, 4.2f);
	Sample2	instance2('B', 24, 2.4f);

	return 0;
}

/*
** Here, when we create an instance of the class Sample1,
** and another instance of the class Sample2.
** 
** Both classes have the same attributes, but the way
** they are initialized is different.
** The use of the initializer list in Sample2 
** is the preferred way to initialize.
**
** compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o InitList main.cpp Sample.class.cpp
*/
