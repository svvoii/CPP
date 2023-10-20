#include "Integer.class.hpp"

Integer::Integer(int const nbr) : _nbr(nbr) {
	std::cout << "Constructor called with value: [" << nbr << "]" << std::endl;
	return;
}

Integer::~Integer(void) {
	std::cout << "Destructor called with value: [" << this->_nbr << "]" << std::endl;
	return;
}

int	Integer::getValue(void) const {
	return this->_nbr;
}

Integer & Integer::operator=(Integer const & rhs) {
	std::cout << "Assignment operator called from: [" << this->_nbr;
	std::cout << "] to: [" << rhs.getValue() << "]" << std::endl;

	this->_nbr = rhs.getValue();

	return *this;
}

Integer Integer::operator+(Integer const & rhs) const {
	std::cout << "Addition operator called with values: [" << this->_nbr;
	std::cout << "] and [" << rhs.getValue() << "]" << std::endl;

	return Integer(this->_nbr + rhs.getValue());
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs) {
	o << rhs.getValue();
	return o;
}

/*
** In this example, we have a class called Integer. With private member _nbr.
** We have a constructor that takes an int as parameter.
**
** We have a getter that returns the value of _nbr.
** We have an assignment operator that takes an Integer as parameter.
** We have an addition operator that takes an Integer as parameter.
**
** We have an overload of the << operator that takes an ostream and an Integer as parameter.
** It returns an ostream reference `std::ostream&`.
** (ostream) by itself is a class in the standard library which is used to output data.
*/
