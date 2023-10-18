/*
** This program demonstrates the use of const.
**
*/

#include <iostream>

#include "Sample.class.hpp"

Sample::Sample(float const fl) : pi(fl), variable(42) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::function(void) const {

	std::cout << "Member function called" << std::endl;
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->variable = " << this->variable << std::endl;

	//this->variable = 0; // error: assignment of member ‘Sample::variable’ in read-only object

	return ;
}

/*
** In this example we are using `this` to access the instance's attributes and methods/functions.
** at the time of the constructor call, the instance is not yet created.
**
** This is not the best practice, there are other ways to use `this` 
** at the time of initialization of the instance.
**
** On the line 28 is the example of the use of `this` 
** to access the instance's `CONST` method/function,
** which will result in a compilation error.
**
** This illustrates the benefit of using `const` to make sure
** that the instance's attributes and methods/functions are not modifiable.
** This is proved to be a good practice which should be utilized
** for good and robust code.
*/