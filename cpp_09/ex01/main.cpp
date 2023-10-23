/*
** RPN Calculator
**
** This program takes inverted Polish mathematical expression as an argument.
**
** The numbers used in this operation and passed as arguments will always be less than 10.
** Program process the expression from the input and output the correct result.
** Program must be able to handle operations with these tokens: `+` `-` `/` `*`
**
** Examples of an expression:
** `./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"` must output: `42`
** `./RPN "7 7 * 7 -"` must output: `42`
** `./RPN "1 2 * 2 / 2 * 2 4 - +"` must output: `0`
** `./RPN "(1 + 1)"` must output: `Error`
**
*/

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	try
	{
		std::cout << calculateRPN(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}	

	return (0);
}
