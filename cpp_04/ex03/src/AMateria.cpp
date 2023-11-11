/*
** Implementation of AMateria class.
*/

#include "../includes/AMateria.hpp"

/*
** Constructors
*/
AMateria::AMateria(void) : _type("default"), _xp(0) {

	std::cout << CYAN << "\t< AMateria default constructor called >" << RESET << std::endl;
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type), _xp(0) {

	std::cout << CYAN << "\t< AMateria parametric constructor called >" << RESET << std::endl;
	//std::cout << "AMateria parametric constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) {

	std::cout << CYAN << "\t< AMateria copy constructor called >" << RESET << std::endl;
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

/*
** Destructor
*/
AMateria::~AMateria(void) {

	std::cout << RED << "\t< AMateria destructor called >" << RESET << std::endl;
	std::cout << std::endl;
	//std::cout << "AMateria destructor called" << std::endl;
}

/*
** Operators overload
*/
AMateria &AMateria::operator=(AMateria const & rhs) {

	std::cout << CYAN << "\t< AMateria assignment operator called >" << RESET << std::endl;
	//std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_xp = rhs.getXP();
	}
	return (*this);
}

/*
** Getters
*/
std::string const &	AMateria::getType(void) const {

	return (this->_type);
}

unsigned int		AMateria::getXP(void) const {

	return (this->_xp);
}

/*
** Public member functions
*/
void				AMateria::use(ICharacter& target) {

	(void)target;
	// adding additional optionality to deduct HP from the target	
	this->_xp += 10;
}
