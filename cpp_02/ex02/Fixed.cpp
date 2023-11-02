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

Fixed::Fixed(void) : _rawBits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int raw) {
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw << this->_fractionalBits;
}

Fixed::Fixed(const float raw) {
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Assignment operator called" << std::endl;
	this->_rawBits = fixed.getRawBits();
	return *this;
}

/*
** `>` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator>(const Fixed &fixed) const {
	return this->_rawBits > fixed.getRawBits();
}

/*
** `<` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator<(const Fixed &fixed) const {
	return this->_rawBits < fixed.getRawBits();
}

/*
** `>=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator>=(const Fixed &fixed) const {
	return this->_rawBits >= fixed.getRawBits();
}

/*
** `<=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator<=(const Fixed &fixed) const {
	return this->_rawBits <= fixed.getRawBits();
}

/*
** `==` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator==(const Fixed &fixed) const {
	return this->_rawBits == fixed.getRawBits();
}

/*
** `!=` operator overload implemented by simply comparing
** raw bits of the two objects and returning a boolean result.
*/
bool	Fixed::operator!=(const Fixed &fixed) const {
	return this->_rawBits != fixed.getRawBits();
}

/*
** `+` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator+(const Fixed &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

/*
** `-` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

/*
** `*` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator*(const Fixed &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

/*
** `/` operator overload implemented by converting both objects
** to float. The result is returned as a new Fixed object.
*/
Fixed	Fixed::operator/(const Fixed &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

/*
** `++` operator overload implemented by incrementing the raw bits
** of the object by one and returning a reference to the object.
*/
Fixed	&Fixed::operator++(void) {
	this->_rawBits++;
	return *this;
}

/*
** `++` operator overload implemented by incrementing the raw bits
** of the object by one and returning a copy of the object.
*/
Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

/*
** `--` operator overload implemented by decrementing the raw bits
** of the object by one and returning a reference to the object.
*/
Fixed	&Fixed::operator--(void) {
	this->_rawBits--;
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
	return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << this->_fractionalBits);
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
