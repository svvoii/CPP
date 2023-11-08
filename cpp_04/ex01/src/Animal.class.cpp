/*
** Definition of Animal class, which is the base class
** for derived class `Cat` and `Dog`.
**
** The focus of this exercise is
** `makeSound()` function, which is declared as virtual in this base class.
** It illustrate the concept of Polimorphism.
** Any derived class from `Animal` will inherit this function and can
** redefine it to be unique to the derived class, and it will be executed
** when called from a derived class object.
*/

#include "../includes/Animal.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
Animal::Animal(void) : _type("<animal>") {

	std::cout << CYAN << "\t< Animal default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Parameterized constructor
** Assigns the type of the animal
*/
Animal::Animal(std::string type) : _type(type) {

	std::cout << CYAN << "\t< Animal name [" << this->_type << "] constructor called >" << RESET << std::endl;
	//std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
Animal::Animal(Animal const &src) {

	this->_type = src._type;
	*this = src;

	std::cout << CYAN << "\t< Animal copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
Animal::~Animal(void) {

	std::cout << RED << "\t< Animal destructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Assignment operator
*/
Animal &Animal::operator=(Animal const &rhs) {

	std::cout << CYAN << "\t< Animal assignment operator called >" << RESET << std::endl;
	std::cout << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Getter, returns the type of the animal
*/
std::string Animal::getType(void) const {

	return (this->_type);
}

/*
** Makes a sound
** This function is declared as virtual in this base class, it will be redefined
** in the derived classes.
*/
void Animal::makeSound(void) const {

	std::cout << "[" << this->_type << "]:";
	std::cout << CYAN << "\t< makes a sound >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** The key to the proper usage of this method/function: `makeSound()` is to
** declare it as `virtual` in the base class `Animal`. And then redefine it
** in the derived classes.
**
** Otherwise, if it is not declared as `virtual` in the base class, then 
** the base class's function is the one which will be executed instead of the
** overridden function in the derived class.
*/
