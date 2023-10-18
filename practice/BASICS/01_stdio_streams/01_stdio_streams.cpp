/*
** Source: 42 Piscine CPP
**
** This program demonstrates the use of the 
** standard input and 
** standard output streams.
*/

#include <iostream>

int	main(void) {

	char	buff[512];

	std::cout << "Hello, World!" << std::endl;

	std::cout << "Enter your name: ";
	std::cin >> buff;
	std::cout << "Your name is: [" << buff << "]" << std::endl;

	return 0;
}

/*
** '<<' is used to redirect the output stream to the console.
** '>>' is used to redirect the input stream from the console.
** 'std::cin' is used to read from the standard input stream.
** 'endl' is used to insert a newline character and flush the output buffer.
**
** About 'endl' vs '\n':
** the new usage of 'endl' compared to C. Adding '\n' as a part of
** the string will work on Linux, however, on macOS there is another character
** for new line. So, introduction of 'endl' is a good practice.
**
** compile with:
** g++ -Wall -Werror -Wextra -Wno-used -o std_in_out 01_stdio_streams.cpp
*/
