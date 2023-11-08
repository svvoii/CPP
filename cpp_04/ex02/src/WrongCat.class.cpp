/*
** Definition of WrongCat class, which is a derived class from `WrongAnimal`.
*/

#include "../includes/WrongCat.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {

	std::cout << CYAN << "\t< WrongCat default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
WrongCat::WrongCat(WrongCat const &src) {

	*this = src;

	std::cout << CYAN << "\t< WrongCat copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
WrongCat::~WrongCat(void) {

	std::cout << RED << "\t< WrongCat destructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Assignment operator
*/
WrongCat &WrongCat::operator=(WrongCat const &rhs) {

	std::cout << CYAN << "\t< WrongCat assignment operator called >" << RESET << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Member function
** Outputs the sound of the animal
** This function is declared in the base class `WrongAnimal`,
** Here we redefine this function to be unique to the `WrongCat` class.
**
** However, the base class's function must be executed instead of this one.
** This is because the base class's function is NOT declared as virtual.
*/
void	WrongCat::makeSound(void) const {

	std::cout << "Wrong cat [" << this->_type << "] is saying:";
	std::cout << GREEN << "\t< Mooooo-oo-o... >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** `makeSound()` method was NOT declared as virtual in the parent class `WrongAnimal`,
** therefore this overwrited method here will NOT be executed.
** Instead, the parent class's method is the one which will be executed.
*/
