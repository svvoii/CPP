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
	
	if (!isValidExpression(argv[1]))
			throw std::runtime_error("Invalid expression");
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}	

	RPNCalculator<int> calculator;
	std::string input = argv[1];

	for (int i = 0; input[i]; i++) {
		if (isspace(input[i])) {
			continue;
		} else if (isInSet(input[i], "0123456789")) {
			calculator.push(input[i] - '0');
		} else if (isInSet(input[i], "+-*/")) {
			calculator.performOperation(input[i]);
		}
	}
	std::cout << calculator.result() << std::endl;

	return (0);
}

/*
** Reverse Polish Notation (RPN) is a mathematical notation 
** in which operators follow their operands. 
** 
** In RPN, the operator is placed after the operands 
** instead of between them. 
** For example, the infix expression 3 + 4 would be written 
** in RPN as 3 4 +.
** 
** RPN is also known as postfix notation. 
** It is called "reverse" because it is the opposite of Polish notation, 
** which places the operator before the operands.
**
** RPN is useful in computer programming because it can be evaluated 
** using a stack data structure. 
** When an operator is encountered, 
** the top two operands are popped off the stack, 
** the operation is performed, 
** and the result is pushed back onto the stack. 
** 
** This process continues until the entire expression has been evaluated, 
** and the final result is left on the stack.
*/