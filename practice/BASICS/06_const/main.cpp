/*
** Source: 42 Piscine CPP
**
** 06_const
** This program demonstrates the use of const.
*/

#include <iostream>
#include "Sample.class.hpp"

int	main(void) {

	Sample	instance(3.14f);

	instance.function();

	return 0;
}

/*
** In this example we are using `const` to make sure 
** that the instance's attributes and methods/functions
** are not modifiable.
**
** This is a good practice and it should be used as much as possible.
**
** compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o Const main.cpp Sample.class.cpp
*/
