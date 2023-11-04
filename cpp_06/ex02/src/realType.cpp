/*
** In here we are implementing our custom functions for 
** identifying the actual type ov the objects.
**
** `Base * generate(void)` randomly generates an instance of
** `A`, `B` or `C` and returns an instance of `Base` pointer.
**
** `void identify(Base * p)` takes a pointer to `Base` as argument
** and prints the actual type of the object. In this case it is
** either `A`, `B` or `C`.
**
** `void identify(Base & p)` takes a reference to `Base` as argument
** and prints the actual type of the object (either `A`, `B` or `C`).
** We are not using a pointer inside this function.
*/

#include "ABC.class.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

enum {
	TYPE_A,
	TYPE_B,
	TYPE_C
};

std::string printType(int type) {
	if (type == TYPE_A) {
		return "TYPE_A";
	}
	else if (type == TYPE_B) {
		return "TYPE_B";
	}
	else if (type == TYPE_C) {
		return "TYPE_C";
	}
	return " Some other type";
}

/*
** This function generates an instance of `A`, `B` or `C`
** using `new` operator and returns a pointer to `Base`.
** So, wewould need to free it later in the main function.
*/
Base * generate(void) {

	int random = rand() % 3;
	Base *base;

	if (random == TYPE_A) {
		base = new A();
	} else if (random == TYPE_B) {
		base = new B();
	} else {
		base = new C();
	}
	std::cout << "Generated [" << printType(random) << "]" << std::endl;

	return base;
}

void identify(Base * p) {

	std::cout << "`identify(Base * p)` via pointer. " << std::endl; 
	std::cout << "Identified as: [ ";

	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << "C" << std::endl;
	}
	std::cout << " ]" << std::endl;
}

void identify(Base & p) {

	std::cout << "`identify(Base & p)` via reference. " << std::endl;
	std::cout << "Identified as: [ ";

	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A ]" << std::endl;
	}
	catch (std::bad_cast &bc) {

		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B ]" << std::endl;
		}
		catch (std::bad_cast &bc) {

			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C ]" << std::endl;
			} 
			catch (std::bad_cast &bc) {
				std::cout << "Unknown type ]" << std::endl;
			}
		}
	}
}
