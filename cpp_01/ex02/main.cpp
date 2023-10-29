#include <iostream>
#include <string>

/*
** This is a simple exmple shows the difference between
** a pointer and a reference in C++.
** With the example of a string variable.
** `stringVariable` is a string variable.
** `stringPTR` is a pointer to a string variable.
** `stringREF` is a reference to a string variable.
**
** The program will simply print the address of each variable
** as well as the value of each variable.
*/

int main(void) {

	std::string stringVariable = "HI THIS IS BRAIN";
	std::string * stringPTR = &stringVariable;
	std::string & stringREF = stringVariable;

	std::cout << "Printing the address of each variable:" << std::endl;
	std::cout << "&stringVariable @:\t" << &stringVariable << std::endl;
	std::cout << "&stringPTR @:\t" << &stringPTR << std::endl;
	std::cout << "&stringREF @:\t" << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Printing the value of each variable:" << std::endl;
	std::cout << "stringVariable:\t" << stringVariable << std::endl;
	std::cout << "*stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl;
	std::cout << std::endl;

	return 0;
}
