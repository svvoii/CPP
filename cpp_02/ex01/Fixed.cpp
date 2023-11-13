/*
** This file contains the implementation of the class Fixed.
** with additional constructors and member functions.
*/
#include "Fixed.hpp"

Fixed::Fixed(void) : 
	_rawBits(0) {

	std::cout << CYAN << "\tDefault constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {

	std::cout << CYAN << "\tCopy constructor called" << RESET << std::endl;
	*this = fixed;
}

/*
** `Fixed(const int raw)` is a constructor that takes a constant
** integer as a parameter and converts it to the corresponding
** fixed point value.
** `_rawBits = raw << _fractionalBits;` this shifts the
** bits of the int `raw` to the left by the number of bits:
** `_fractionalBits` (8) and assigns the result to the `_rawBits`.
*/
Fixed::Fixed(const int raw) {
	
	std::cout << CYAN << "\tInt constructor called" << RESET;
	std::cout << " with: [" << raw << "] as an argument" << std::endl;
	_rawBits = raw << _fractionalBits;
	//this->_rawBits = raw << this->_fractionalBits; // same as above
}

/*
** `Fixed(const float raw)` is a constructor that takes a constant
** floating point number as a parameter and converts it to the
** corresponding fixed point value.
** `_rawBits = roundf(raw * (1 << _fractionalBits));` this
** multiplies the floating point number `raw` by the number of bits
** `_fractionalBits` (8).
** `1 << _fractionalBits` shifts the bits of the integer 1
** to the left by the number of bits `_fractionalBits`.
** `roundf()` rounds the result of the multiplication to the nearest
** integer value.
*/
Fixed::Fixed(const float raw) {

	std::cout << CYAN << "\tFloat constructor called" << RESET;
	std::cout << " with: [" << raw << "] as an argument" << std::endl;
	_rawBits = roundf(raw * (1 << _fractionalBits));
	//this->_rawBits = roundf(raw * (1 << this->_fractionalBits)); // same as above
}

Fixed::~Fixed(void) {

	std::cout << RED << "\tDestructor called" << RESET << std::endl;
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {

	std::cout << "Assignment operator called" << std::endl;
	_rawBits = fixed._rawBits;
	//this->_rawBits = fixed.getRawBits(); // same as above
	return *this;
}

int Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called";
	std::cout << " with: [" << raw << "] as an argument" << std::endl;
	this->_rawBits = raw;
}

/*
** `int toInt(void) const` converts the fixed point value to
** an integer value.
** `_rawBits >> _fractionalBits` shifts the bits of the `_rawBits`
** to the right by the number of bits `_fractionalBits` (8).
*/
int Fixed::toInt(void) const {

	return _rawBits >> _fractionalBits;
	//return this->_rawBits >> this->_fractionalBits; // same as above
}

/*
** `float toFloat(void) const` converts the fixed point value to
** a floating point value.
** `(float)_rawBits` casts the `_rawBits` to a floating point number.
** `(1 << _fractionalBits)` shifts the bits of the integer 1
** to the left by the number of bits `_fractionalBits` (8).
*/
float Fixed::toFloat(void) const {

	return (float)_rawBits / (1 << _fractionalBits);
	// return (float)this->_rawBits / (1 << this->_fractionalBits);
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
