/*
** Source: 42 Piscine CPP
**
** This program demonstrates the use of namespaces.
*/

//#include <iostream>
#include <stdio.h>

int	gl_var = 1;		// global variable
int	f(void) { return 2; }	// global function

namespace Foo
{
	int	gl_var = 3;		// global variable
	int	f(void) { return 4; }	// global function
}

namespace Bar
{
	int	gl_var = 5;		// global variable
	int	f(void) { return 6; }	// global function
}

/*
** alias, it is not a copy, it is just another name
*/
namespace Muf = Bar;

/*
** '::' is the global scope operator / scope resolution operator
** it is used to access global variables and functions
** of the given namespace
**
** The first two lines of the main function are equivalent to
** the last two lines of the main function.
*/
int	main(void) {

	printf("gl_var: 	[%d]\n", gl_var);
	printf("f():		[%d]\n\n", f());

	printf("Foo::gl_var:	[%d]\n", Foo::gl_var);
	printf("Foo::f():	[%d]\n\n", Foo::f());

	printf("Bar::gl_var:	[%d]\n", Bar::gl_var);
	printf("Bar::f():	[%d]\n\n", Bar::f());

	printf("Muf::gl_var:	[%d]\n", Muf::gl_var);
	printf("Muf::f():	[%d]\n\n", Muf::f());

	printf("::gl_var:	[%d]\n", ::gl_var);
	printf("::f():		[%d]\n\n", ::f());

	return (0);
}

/*
** compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o namespace 00_namespace.cpp
*/
