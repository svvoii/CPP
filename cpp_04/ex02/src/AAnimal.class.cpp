/*
** Definition of AAnimal class, which is the base class
** for derived class `Cat` and `Dog`.
**
** This instance of the base class is an abstract class, 
** because it contains a pure virtual function, which is
** `makeSound()`, it is declared as 
** `virtual void makeSound(void) const = 0;`, and it is 
** NOT defined in the base class, here.
*/

#include "../includes/AAnimal.class.hpp"

/*
** Default constructor
** Assigns the type of the AAnimal
*/
AAnimal::AAnimal(void) : _type("<AAnimal>") {

	std::cout << CYAN << "\t< AAnimal default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Parameterized constructor
** Assigns the type of the AAnimal
*/
AAnimal::AAnimal(std::string type) : _type(type) {

	std::cout << CYAN << "\t< AAnimal name [" << this->_type << "] constructor called >" << RESET << std::endl;
	//std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
AAnimal::AAnimal(AAnimal const &src) {

	this->_type = src._type;
	*this = src;

	std::cout << CYAN << "\t< AAnimal copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
AAnimal::~AAnimal(void) {

	std::cout << RED << "\t< AAnimal destructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Assignment operator
*/
AAnimal &AAnimal::operator=(AAnimal const &rhs) {

	std::cout << CYAN << "\t< AAnimal assignment operator called >" << RESET << std::endl;
	std::cout << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Getter, returns the type of the AAnimal
*/
std::string AAnimal::getType(void) const {

	return (this->_type);
}

/*
** Makes a sound
** This function is declared as virtual in this base class, it will be redefined
** in the derived classes.
void AAnimal::makeSound(void) const {

	std::cout << "[" << this->_type << "]:";
	std::cout << CYAN << "\t< makes a sound >" << RESET << std::endl;
	std::cout << std::endl;
}
*/

/*
** The key to the proper usage of this method/function: `makeSound()` is to
** declare it as `virtual` in the base class `AAnimal`. And then redefine it
** in the derived classes.
**
** Otherwise, if it is not declared as `virtual` in the base class, then 
** the base class's function is the one which will be executed instead of the
** overridden function in the derived class.
*/
