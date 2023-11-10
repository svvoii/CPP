/*
** Implementation of Ice class, which inherits from AMateria.
*/

#include "../includes/Ice.hpp"

/*
** Constructors
*/
Ice::Ice(void) : AMateria("ice") {

	std::cout << CYAN << "\t< Ice default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src) {

	std::cout << CYAN << "\t< Ice copy constructor called >" << RESET << std::endl;
}

/*
** Destructor
*/
Ice::~Ice(void) {

	std::cout << RED << "\t< Ice destructor called >" << RESET << std::endl;
}

/*
** Operators overload
*/
Ice &	Ice::operator=(Ice const & rhs) {

	std::cout << CYAN << "\t< Ice assignment operator called >" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_xp = rhs.getXP();
	}
	return (*this);
}

/*
** Public member functions
*/
AMateria*	Ice::clone(void) const {

	return (new Ice(*this));
}

void		Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	this->_xp += 10;
}
