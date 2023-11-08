/*
** Definition of WrongAnimal class
**
** The idea of this class is to show that if a derived class's member function
** is not declared as `virtual` in the base class, then it will be the one 
** executed from any derived class which inherits from this base class.
**
** So, the focus here is on the `makeSound()` member function.
*/

#include "../includes/WrongAnimal.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
WrongAnimal::WrongAnimal(void) : _type("<wrong animal>") {

	std::cout << CYAN << "\t< WrongAnimal default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Parameterized constructor
** Assigns the type of the animal
*/
WrongAnimal::WrongAnimal(std::string type) : _type(type) {

	std::cout << CYAN << "\t< WrongAnimal name [" << this->_type << "] constructor called >" << RESET << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
WrongAnimal::WrongAnimal(WrongAnimal const &src) {

	this->_type = src._type;
	*this = src;

	std::cout << CYAN << "\t< WrongAnimal copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
WrongAnimal::~WrongAnimal(void) {

	std::cout << RED << "\t< WrongAnimal destructor called >" << RESET << std::endl;
}

/*
** Assignment operator
*/
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {

	std::cout << CYAN << "\t< WrongAnimal assignment operator called >" << RESET << std::endl;
	std::cout << std::endl;

	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/*
** Getter for `_type`
*/
std::string WrongAnimal::getType(void) const {

	return (this->_type);
}

/*
** `makeSound` method for `WrongAnimal` class was NOT declared as virtual, therefore
** it will be the one executed from any derived class.
*/
void	WrongAnimal::makeSound(void) const {

	std::cout << "[" << this->_type << "] is saying:";
	std::cout << MAGENTA << "\t< ... wake up Neo.. Matrix has you.. >" << RESET << std::endl;
	std::cout << std::endl;
}	

/*
** In this example we have the `WrongAnimal` class, which is the base class,
** and its method `makeSound()` which is NOT declared as `virtual`.
** So, no matter how this method is redefined in the derived classe `WrongCat`,
** the base class's implementation will be the priority to be executed.
*/