/*
** This file contains the implementation of the class Fixed.
** with additional constructors and member functions.
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
** `Fixed(const int raw)` is a constructor that takes a constant
** integer as a parameter and converts it to the corresponding
** fixed point value.
** `this->_rawBits = raw << this->_fractionalBits;` shifts the
** bits of the integer `raw` to the left by the number of bits
** `_fractionalBits` and assigns the result to the `_rawBits`.
*/
Fixed::Fixed(const int raw) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw << this->_fractionalBits;
}

/*
** `Fixed(const float raw)` is a constructor that takes a constant
** floating point number as a parameter and converts it to the
** corresponding fixed point value.
** `this->_rawBits = roundf(raw * (1 << this->_fractionalBits));`
** multiplies the floating point number `raw` by the number of bits
** `_fractionalBits`.
** `1 << this->_fractionalBits` shifts the bits of the integer 1
** to the left by the number of bits `_fractionalBits`.
** `roundf()` rounds the result of the multiplication to the nearest
** integer value.
** The result is assigned to the `_rawBits` member variable.
*/
Fixed::Fixed(const float raw) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(raw * (1 << this->_fractionalBits));
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

/*
** `int toInt(void) const` converts the fixed point value to
** an integer value.
** `this->_rawBits >> this->_fractionalBits` shifts the bits
** of the `_rawBits` to the right by the number of bits `_fractionalBits`.
*/
int Fixed::toInt(void) const {
	return this->_rawBits >> this->_fractionalBits;
}

/*
** `float toFloat(void) const` converts the fixed point value to
** a floating point value.
** `(float)this->_rawBits` casts the `_rawBits` to a floating point number.
** `(1 << this->_fractionalBits)` shifts the bits of the integer 1
** to the left by the number of bits `_fractionalBits`.
*/
float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << this->_fractionalBits);
}

/*
** `std::ostream &operator<<(std::ostream &out, const Fixed &fixed)`
** is the overload of the output operator `<<` so that it can be used
** with the `Fixed` class.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
