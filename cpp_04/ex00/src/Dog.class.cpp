/*
** This is the definition of the Dog class, which is a derived class
** of the Animal class.
*/

#include "../includes/Dog.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
Dog::Dog(void) : Animal("Dog") {

	std::cout << CYAN << "\t< Dog default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
Dog::Dog(Dog const &src) {

	*this = src;

	std::cout << CYAN << "\t< Dog copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
Dog::~Dog(void) {

	std::cout << RED << "\t< Dog destructor called >" << RESET << std::endl;
}

/*
** Assignment operator
*/
Dog &Dog::operator=(Dog const &rhs) {

	std::cout << CYAN << "\t< Dog assignment operator called >" << RESET << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Member function
** Outputs the sound of the animal
** This function is declared as virtual in the base class `Animal`,
** Here we redefine this function to be unique to the `Dog` class.
*/
void	Dog::makeSound(void) const {

	std::cout << "[" << this->_type << "] is saying:";
	std::cout << GREEN << "\t< Woof woof >" << RESET << std::endl;
	std::cout << std::endl;
}
