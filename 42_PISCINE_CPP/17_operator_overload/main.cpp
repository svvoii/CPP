/*
** Source: 42 Piscine CPP
**
** 17_operator_overload
**
** This program demonstrates the use of 
** operator overloading in C++.
**
** Some notion about operators:
** `+(1, 1)` is called prefix notation or infunctional notation 
** `1 + 1` is called infix notation
** `1 1 +` is called postfix notation
**
** `+(1, 1)` this is called prefix notation or infunctional notation 
** `1.+(1)` can be applied to an object of type Integer
**
** This will allow to make stack calculations. 
** Also called Reverse Polish Notation.
*/
#include <iostream>
#include "Integer.class.hpp"

int main() {
	
	Integer		x( 42 );
	Integer		y( 21 );
	Integer		z( 0 );

	std::cout << "Value of x: [" << x << "]" << std::endl;
	std::cout << "Value of y: [" << y << "]" << std::endl;
	std::cout << "Value of z: [" << z << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "(y = Integer( 19 )) will create a new Integer object and assign it to y" << std::endl;
	y = Integer( 19 );
	std::cout << "Value of y: [" << y << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "(z = x + y) will create a new Integer object and assign it to z" << std::endl;
	z = x + y;
	std::cout << "Value of z: [" << z << "]" << std::endl;
	std::cout << std::endl;

	return 0;
}

/*
** In the example above, we have a main function that creates 3 instances of Integer.
** 
** `y = Integer( 19 );` in this case would be the same as `y = 19;`
** `z = x + y;` in this case would be the same as `z = x.operator+(y);`
** This is an example of operator overloading.
** `x` and `y` are objects of type Integer.
** `operator+` is a method of the Integer class.
** `+` is an operator which declered as a method of the Integer class.
**
** compile with:
** c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o operator_overload
*/
