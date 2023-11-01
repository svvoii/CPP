/*
** This file contains the implementation of the class Fixed.
*/
#include "Fixed.hpp"

/*
** `Fixed(void)` is the default constructor.
** ` : _rawBits(0)` initializes the private member `_rawBits` 
** with the integer literal 0.
*/
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
** `Fixed(const Fixed &fixed)` is the copy constructor.
** It is called when an object is declared and initialized
** with another object of the same type.
** Example of the object instantiation in the main function:
** `Fixed a(b);` or `Fixed a = b;`.
** This also invokes the assignment operator overload, 
** which is triggered by the `=` sign in: `*this = fixed;`.
*/
Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/*
** `~Fixed(void)` is the destructor of the class.
** It is called when an object is destroyed, for example,
** when the program ends.
*/
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/*
** `Fixed &operator=(const Fixed &fixed)` is the 
** assignment operator overload.
** It is called when an object is assigned to another object
** of the same type.
** Example of the object assignment in the main function:
** `a = b;`.
*/
Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignment operator called" << std::endl;
	this->_rawBits = fixed.getRawBits();
	return *this;
}

/*
** `int getRawBits(void) const` returns the raw value of
** the fixed point number.
** In this case the value `_rawBits` is returned as a copy.
** `const` at the end of the function declaration means that
** this function cannot modify the object `*this` on which it is called.
*/
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

/*
** `void setRawBits(int const raw)` sets the raw value of
** the fixed point number.
** The `raw` argument is assigned to the `_rawBits` member.
** `const` in the argument declaration means that this argument
** `raw` cannot be modified inside the function.
*/
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called";
	std::cout << " with: [" << raw << "] as an argument" << std::endl;
	this->_rawBits = raw;
}
