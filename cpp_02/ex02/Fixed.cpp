/*
** This file contains the implementation of the class Fixed.
** with additional constructors and member functions.
** The new initialized methods are mostly operators, 
** see the comments bellow.
**
** Comments for all other methods can be found in the previous
** exercises. In the respective file.
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

Fixed::Fixed(const int raw) {

	std::cout << CYAN << "\tInt constructor called" << RESET << std::endl;
	_rawBits = raw << _fractionalBits;
}

Fixed::Fixed(const float raw) {

	std::cout << CYAN << "\tFloat constructor called" << RESET << std::endl;
	_rawBits = roundf(raw * (1 << _fractionalBits));
}

Fixed::~Fixed(void) {

	std::cout << RED << "\tDestructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {

	std::cout << CYAN << "\tAssignment operator called" << RESET << std::endl;

	_rawBits = fixed._rawBits;
	return *this;
}

/*
** `>` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator>(const Fixed &fixed) const {

	return _rawBits > fixed._rawBits;
}

/*
** `<` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator<(const Fixed &fixed) const {

	return _rawBits < fixed._rawBits;
}

/*
** `>=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator>=(const Fixed &fixed) const {

	return _rawBits >= fixed._rawBits;
}

/*
** `<=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator<=(const Fixed &fixed) const {

	return _rawBits <= fixed._rawBits;
}

/*
** `==` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator==(const Fixed &fixed) const {

	return _rawBits == fixed._rawBits;
}

/*
** `!=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator!=(const Fixed &fixed) const {

	return _rawBits != fixed._rawBits;
}

/*
** `+` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator+(const Fixed &fixed) const {

	//return Fixed(_rawBits + fixed._rawBits);
	return Fixed(this->toFloat() + fixed.toFloat());
}

/*
** `-` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator-(const Fixed &fixed) const {

	//return Fixed(_rawBits - fixed._rawBits);
	return Fixed(this->toFloat() - fixed.toFloat());
}

/*
** `*` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator*(const Fixed &fixed) const {

	//return Fixed(_rawBits * fixed._rawBits >> _fractionalBits);
	return Fixed(this->toFloat() * fixed.toFloat());
}

/*
** `/` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator/(const Fixed &fixed) const {

	if (fixed.toFloat() == 0)
	{
		std::cout << RED << "Error: Division by zero, output undefined" << RESET << std::endl;
		//return Fixed(0);
	}
	//return Fixed(_rawBits * (1 << _fractionalBits) / fixed._rawBits);
	return Fixed(this->toFloat() / fixed.toFloat());
}

/*
*/
Fixed	&Fixed::operator++(void) {

	_rawBits++;
	//this->_rawBits++; // same as above
	return *this;
}

/*
** `operator++(int)` is a postfix increment operator.
** The `int` argument is a dummy argument that is used to
** differentiate between the prefix and postfix increment operators.
** The `int` argument is never used in the function.
** The postfix increment operator returns a copy of the object
** before the increment.
** It creates `Fixed` object `tmp` and initializes it with the
** current object `*this`. 
** Then it call the prefix increment operator `operator++()` on the
** current object `*this` and returns the `tmp` copy of the object.
*/
Fixed	Fixed::operator++(int) {

	Fixed tmp = *this;
	//Fixed tmp(*this); // same as above
	operator++();
	//this->operator++(); // same as above
	return tmp;
}

/*
** `--` operator overload implemented by decrementing the raw bits
** of the object by one and returning a reference to the object.
*/
Fixed	&Fixed::operator--(void) {

	_rawBits--;
	return *this;
}

/*
** `--` operator overload implemented by decrementing the raw bits
** of the object by one and returning a copy of the object.
*/
Fixed	Fixed::operator--(int) {

	Fixed tmp(*this);
	operator--();
	return tmp;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called";
	// std::cout << " with: [" << raw << "] as an argument" << std::endl;
	this->_rawBits = raw;
}

int Fixed::toInt(void) const {

	return _rawBits >> _fractionalBits;
}

float Fixed::toFloat(void) const {

	return (float)_rawBits / (1 << _fractionalBits);
}

/*
** This function returns back a reference to the biggest of the two
** objects passed as arguments.
** `Fixed &Fixed` means that the method returns a reference to a Fixed object.
*/
Fixed &Fixed::min(Fixed &a, Fixed &b) {

	return a < b ? a : b;
}

/*
** This function returns back a reference to the biggest of the two
** objects passed as arguments.
** `const` means that the objects it returns cannot be modified.
*/
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {

	return a < b ? a : b;
}

/*
** This function returns back a reference to the biggest of the two
** objects passed as arguments.
** `Fixed &Fixed` means that the method returns a reference to a Fixed object.
*/
Fixed &Fixed::max(Fixed &a, Fixed &b) {

	return a > b ? a : b;
}

/*
** This function returns back a reference to the biggest of the two
** objects passed as arguments.
** `const` means that the objects it returns cannot be modified.
*/
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {

	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {

	out << fixed.toFloat();
	return out;
}
