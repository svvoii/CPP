/*
** Definition of Cat class, which is a derived class from `Animal`.
*/

#include "../includes/Cat.class.hpp"
#include "../includes/Brain.class.hpp"

/*
** Default constructor
** Assigns the type of the animal
*/
Cat::Cat(void) : Animal("Cat") {

	// additional syntax to make an instance of the Brain object
	this->_brain = new Brain();

	std::cout << CYAN << "\t< Cat default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Copy constructor
** Declare as deleted
*/
Cat::Cat(Cat const &src) {

	// additional syntax to make a deep copy of the Brain object
	this->_brain = new Brain();
	this->_copyBrain(*src._brain);

	*this = src;

	std::cout << CYAN << "\t< Cat copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

/*
** Destructor
*/
Cat::~Cat(void) {

	// additional syntax to delete the Brain object
	this->_deleteBrain();

	std::cout << RED << "\t< Cat destructor called >" << RESET << std::endl;
}

/*
** Assignment operator
*/
Cat &Cat::operator=(Cat const &rhs) {

	std::cout << CYAN << "\t< Cat assignment operator called >" << RESET << std::endl;

	// additional syntax to make a deep copy of the Brain object
	if (this != &rhs) {
		this->_deleteBrain();
		this->_brain = new Brain();
		this->_copyBrain(*rhs._brain);
		this->_type = rhs._type;
	}
	return (*this);
}

/*
** Definition of new private member functions,
** `_copyBrain()`
void	Cat::_copyBrain(Brain const &src) {
	
	// ..deep copy of the Brain object
	for (int i = 0; i < 100; i++) {
		this->_brain->setIdea(i, src.getIdea(i));
	}
}
*/
void	Cat::_copyBrain(Brain const &src) {

	// deep copy of the Brain object is done by the Brain class
	*this->_brain = src;
}

/*
** `_deleteBrain()`
*/
void	Cat::_deleteBrain(void) {

	delete this->_brain;
	this->_brain = NULL;
	
	std::cout << RED << "\t< Cat's brain deleted >" << RESET << std::endl;
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
