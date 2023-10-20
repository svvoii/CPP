/*
** GitHub Copilot: In C++, a reference is an alias to an existing object, 
** while a pointer is a variable that stores the memory address of an object. 
**
** References are declared using the `&` symbol and must be initialized to an existing object. 
** Once initialized, a reference cannot be changed to refer to a different object. 
** References are often used as function parameters to avoid copying large objects.
**
** Pointers are declared using the `*` symbol and can be initialized to a memory address 
** using the address-of operator `&`. 
**
** Pointers can be reassigned to point to a different object. 
** Pointers are often used to dynamically allocate memory or to pass around null values.
** 
** Both references and pointers can be used to modify the value of an object, 
** but references provide a more intuitive syntax for accessing the object's members. 
** However, pointers provide more flexibility and can be used to perform pointer arithmetic 
** and to create dynamic data structures.
*/

#include <iostream>

// Function that takes a reference to an integer and modifies it
void increment(int& num) {
	num++;
}

int main() {
	int x = 5;

	
	int* ptr = &x; // a pointer to x
	int& ref = x; // a reference to x

	/* Print the value of x as it is, with the pointer and the reference */
	std::cout << "x = " << x << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;
	std::cout << "ref = " << ref << std::endl;
	std::cout << std::endl;

	/* Modify the value of x through the pointer */
	std::cout << "using: '*ptr = 10' to change the value of x: [" << x << "]" << std::endl;
	*ptr = 10;

	/* Print the value of x with the pointer and the reference */
	std::cout << "x = " << x << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;
	std::cout << "ref = " << ref << std::endl;
	std::cout << std::endl;

	/* Modify the value of x through the reference */
	std::cout << "using: 'ref = 42' to change the value of x: [" << x << "]" << std::endl;
	ref = 42;

	/* Print the new value of x and the reference */
	std::cout << "x = " << x << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;
	std::cout << "ref = " << ref << std::endl;
	std::cout << std::endl;

	/* Pass x as a reference to the increment function */
	std::cout << "Passing x as a reference to the increment function" << std::endl;
	increment(x);

	// Print the new value of x and the reference
	std::cout << "x = " << x << std::endl;
	std::cout << "*ptr = " << *ptr << std::endl;
	std::cout << "ref = " << ref << std::endl;

	return 0;
}

/*
** References are also called aliases.
**
** References are not new variables, they are just new names for existing variables.
** References are declared with the `&' symbol.
** References are not pointers and not variables.
**
** References cannot be reassigned. Once a reference is assigned to a variable, 
** it cannot be reassigned to another variable.
** This also means that:
** references cannot exist without a variable and cannot be NULL.
** `int& ref;' is invalid declaration.
*/