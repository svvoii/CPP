/*
** This file contains the implementation of the class Fixed.
** See `Fixed.hpp` for more details.
**
** Comments for all the methods can be found in the previous
** exercises. In the respective file.
*/
#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int raw) {
	this->_rawBits = raw << this->_fractionalBits;
}

Fixed::Fixed(const float raw) {
	this->_rawBits = roundf(raw * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void) {
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->_rawBits = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed) const {
	return this->_rawBits > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const {
	return this->_rawBits < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const {
	return this->_rawBits >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const {
	return this->_rawBits <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const {
	return this->_rawBits == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const {
	return this->_rawBits != fixed.getRawBits();
}

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
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++(void) {
	this->_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--(void) {
	this->_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
