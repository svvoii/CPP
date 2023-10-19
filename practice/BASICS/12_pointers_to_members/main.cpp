/*
** Source: 42 Piscine CPP
**
** 12_pointers_to_members
**
** This program demonstrates the use of pointers to members of a class.
*/

#include <iostream>
#include "Sample.class.hpp"

int main() {
	
	Sample	classInstance;
	Sample	*instancePtr = &classInstance;

	int		Sample::*pointToIntMember = NULL;
	void	(Sample::*f)(void) const;

	pointToIntMember = &Sample::variable;

	std::cout << "Value of the member variable: " << classInstance.variable << std::endl;

	classInstance.*pointToIntMember = 21;
	std::cout << "Value of the member variable: " << classInstance.variable << std::endl;

	instancePtr->*pointToIntMember = 42;
	std::cout << "Value of the member variable: " << classInstance.variable << std::endl;

	f = &Sample::function;

	(classInstance.*f)();
	(instancePtr->*f)();

	return 0;
}

/*
** In C++, pointers to members of a class are declared with the `::*` operator.
** `::*` is used to declare a pointer to a member of a class.
** `.*` is used to access a member of a class through a pointer to a member of a class.
** `->*` is used to access a member of a class through a pointer to an instance of a class.
**
** In the main function above, we first declare an instance of the Sample class:
** `classInstance` 
** and a pointer to an instance of the Sample class:
** `instancePtr` where we assign the address of the instance `classInstance`.
**
** We then declare a pointer to a member of the Sample class using the folowing syntax:
** `int Sample::*pointToIntMember = NULL;`
** This declares a pointer to a member of the Sample class that is of type `int`.
** This pointer is initialized to `NULL` and not yet assigned to any member of the Sample class.
**
** We then declare a pointer to a member function of the Sample class using the folowing syntax:
** `void (Sample::*f)(void) const;`
** This declares a pointer to a member function of the Sample class.
** This pointer to a member function not yet assigned to any member function of the Sample class.
**
** We then assign the address of the member variable `variable` to the pointer `pointToIntMember`:
** `pointToIntMember = &Sample::variable;`
** This assigns the address of the member variable `variable` to the pointer `pointToIntMember`.
**
** After printing the value of the member variable `variable` of the instance `instance`,
** (which hasn't been changed yet), we then assign the value 21 to the member `variable`
** using the pointer to the member `pointToIntMember` and the `.*` operator:
** `instance.*pointToIntMember = 21;` and print it again.
**
** Similarly, we use the pointer to the member `pointToIntMember` and the `->*` operator
** to assign the value 42 to the member `variable` of the instance `instancePtr` pointer:
** `instancePtr->*pointToIntMember = 42;` and print it again.
**
** We then assign the address of the member function `function` to the pointer `f`:
** `f = &Sample::function;`
** This assigns the address of the member function `function` to the pointer `f`.
**
** We then call the member function `function` of the instance `instance` using the pointer `f`
** and the `.*` operator:
** `(instance.*f)();`
**
** Similarly, we call the member function `function` of the instance `instancePtr` using the pointer `f`
** and the `->*` operator:
** `(instancePtr->*f)();`
**
** Compile with:
** g++ -Wall -Wextra -Werror -std=c++98 -o PointersToMembers main.cpp Sample.class.cpp
*/
