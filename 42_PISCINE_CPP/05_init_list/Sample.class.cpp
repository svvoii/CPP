/*
** 05_init_list
**
** This program demonstrates the use of initializer lists.
**
** use of the initializer list in Sample2.
*/

#include <iostream>

#include "Sample.class.hpp"

Sample1::Sample1(char c, int num, float fl) {

	std::cout << "Constructor called" << std::endl;

	this->c_var = c;
	std::cout << "this->c_var: " << this->c_var << std::endl;

	this->num_var = num;
	std::cout << "this->num_var: " << this->num_var << std::endl;

	this->fl_var = fl;
	std::cout << "this->fl_var: " << this->fl_var << std::endl;

	return ;
}

Sample1::~Sample1(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
** The usage in Sample1 is not the best way to initialize
** and must be avoided.
*/

/************************************************************/

Sample2::Sample2(char c, int num, float fl) : c_var(c), num_var(num), fl_var(fl) {

	std::cout << "Constructor called" << std::endl;

	std::cout << "this->c_var: " << this->c_var << std::endl;
	std::cout << "this->num_var: " << this->num_var << std::endl;
	std::cout << "this->fl_var: " << this->fl_var << std::endl;

	return ;
}

Sample2::~Sample2(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
** The `initializer list` usage in Sample2 is the 
** prefered way to initialize instances of a class.
** 
** By using the initializer list, we initialize the 
** attributes of the class to the values passed to 
** the constructor of the given Class.
**
** We can do this with constant variables as well.
** Which is illustrated in the next example (06_const).
*/