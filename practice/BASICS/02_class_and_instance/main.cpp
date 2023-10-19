/*
** Source: 42 Piscine CPP
**
** 02_class_and_instance
**
** In `class.hpp` we declare the Class and its attributes,
** functions / methods.
**
** In .cpp we define the attributes, functions / methods
** which are declared in `.class.hpp`
**
*/

#include "Sample.class.hpp"

int	main(void) {

	Sample	instance; // instance of the class Sample

	return 0;
}

/*
** As well as in C, if we declare a variable in a function,
** it will be destroyed once the function is finished.
** So, the instance of the class Sample will be destroyed by the destructor.
**
** compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o SampleClass main.cpp Sample.class.cpp
*/
