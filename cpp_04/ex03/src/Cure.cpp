/*
** Implementation of Cure class which inherits from AMateria.
*/

#include "../includes/Cure.hpp"

/*
** Constructors
*/
Cure::Cure(void) : AMateria("cure") {

	std::cout << CYAN << "\t< Cure default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {

	std::cout << CYAN << "\t< Cure copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
Cure::~Cure(void) {

	std::cout << RED << "\t< Cure destructor called >" << RESET << std::endl;
}

/*
** Operators overload
*/
Cure &	Cure::operator=(Cure const & rhs) {

	std::cout << CYAN << "\t< Cure assignment operator called >" << RESET << std::endl;
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
AMateria*	Cure::clone(void) const {

	return (new Cure(*this));
}

void		Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	this->_xp += 10;
}
