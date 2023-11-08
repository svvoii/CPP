/*
** Definition of Cat class, which is a derived class from `Animal`.
*/

#include "../includes/Cat.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
Cat::Cat(void) : Animal("Cat") {

	std::cout << CYAN << "\t< Cat default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
Cat::Cat(Cat const &src) {

	*this = src;

	std::cout << CYAN << "\t< Cat copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
Cat::~Cat(void) {

	std::cout << RED << "\t< Cat destructor called >" << RESET << std::endl;
}

/*
** Assignment operator
*/
Cat &Cat::operator=(Cat const &rhs) {

	std::cout << CYAN << "\t< Cat assignment operator called >" << RESET << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Member function
** Outputs the sound of the animal
** This function is declared as virtual in the base class `Animal`,
** Here we redefine this function to be unique to the `Cat` class.
*/
void	Cat::makeSound(void) const {

	std::cout << "[" << this->_type << "] is saying:";
	std::cout << GREEN << "\t< Meeeooooww... >" << RESET << std::endl;
	std::cout << std::endl;
}
