/*
** This file contains the implementation of the class Fixed.
** See `Fixed.hpp` for more details.
**
** Comments for all the methods can be found in the previous
** exercises. In the respective file.
*/
#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : 
	_rawBits(0) {
	//std::cout << CYAN << "\tDefault constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {

	//std::cout << CYAN << "\tCopy constructor called" << RESET << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int raw) {

	//std::cout << CYAN << "\tInt constructor called" << RESET << std::endl;
	this->_rawBits = raw << this->_fractionalBits;
}

Fixed::Fixed(const float raw) {

	//std::cout << CYAN << "\tFloat constructor called" << RESET << std::endl;
	this->_rawBits = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void) {

	//std::cout << RED << "\tDestructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {

	//std::cout << CYAN << "\tAssignment operator called" << RESET << std::endl;

	_rawBits = fixed._rawBits;
	return *this;
}

/*
** LOGICAL OPERATORS OVERLOADS `>`, `<`, `>=`, `<=`, `==`, `!=`
*/
bool	Fixed::operator>(const Fixed &fixed) const {

	return _rawBits > fixed._rawBits;
}

bool	Fixed::operator<(const Fixed &fixed) const {

	return _rawBits < fixed._rawBits;
}

bool	Fixed::operator>=(const Fixed &fixed) const {

	return _rawBits >= fixed._rawBits;
}

bool	Fixed::operator<=(const Fixed &fixed) const {

	return _rawBits <= fixed._rawBits;
}

bool	Fixed::operator==(const Fixed &fixed) const {

	return _rawBits == fixed._rawBits;
}

bool	Fixed::operator!=(const Fixed &fixed) const {

	return _rawBits != fixed._rawBits;
}

/*
** ARITHMETIC OPERATORS OVERLOADS `+`, `-`, `*`, `/`
*/
Fixed	Fixed::operator+(const Fixed &fixed) const {

	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const {

	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const {

	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const {

	if (fixed.toFloat() == 0) {
		std::cout << RED << "ATTENTION: Division by zero, output undefined" << RESET << std::endl;
		// return fixed;
	}
	return Fixed(this->toFloat() / fixed.toFloat());
}

/*
** INCREMENT AND DECREMENT OPERATORS OVERLOADS `++`, `--`
*/
Fixed	&Fixed::operator++(void) {

	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {

	Fixed tmp = *this;
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--(void) {

	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {

	Fixed tmp = *this;
	operator--();
	return tmp;
}

/*
** GETTERS AND SETTERS
*/
int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

int Fixed::toInt(void) const {
	return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << this->_fractionalBits);
}

/*
** MIN AND MAX FUNCTIONS
*/
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return a > b ? a : b;
}

/*
** OUTPUT OPERATOR OVERLOAD `<<`
** returns a float representation of the fixed point value of the object.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {

	out << fixed.toFloat();
	return out;
}
