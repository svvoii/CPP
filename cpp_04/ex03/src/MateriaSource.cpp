/*
** This is the implementation of the `MateriaSource` class.
** It is a class that inherits from the `IMateriaSource` Interface.
**
** `MaterialSource` is a class that has an array of 4 pointers to `AMateria`.
** It has a function `learnMateria` that takes a pointer to `AMateria` as a parameter.
** It has a function `createMateria` that takes a string as a parameter.
**
** In a nutshell `MateriaSource` is able to learn and create `AMateria`.
** It is able to generate a new `AMateria` from a string, which is its type.
*/

#include "../includes/MateriaSource.hpp"

/*
** Constructors
*/
MateriaSource::MateriaSource(void) {

	std::cout << CYAN << "\t< MateriaSource default constructor called >" << RESET << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {

	std::cout << CYAN << "\t< MateriaSource copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;

	*this = src;
}

/*
** Destructor
*/
MateriaSource::~MateriaSource(void) {

	std::cout << RED << "\t< MateriaSource destructor called >" << RESET << std::endl;
	this->_deleteMateria();
}

/*
** Operators overload
*/
MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs) {

	std::cout << CYAN << "\t< MateriaSource assignment operator called >" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_deleteMateria();
		this->_copyMateria(rhs);
	}
	return (*this);
}

/*
** Testing purposes
*/
int	MateriaSource::getInventorySize(void) const {

	int inventorySize = 0;

	for (int i = 0; i < 4; i++) {

		if (this->_materia[i] != NULL) {
			inventorySize++;
		}
	}
	return (inventorySize);
}

void	MateriaSource::printMateria(void) {

	for (int i = 0; i < 4; i++) {

		if (this->_materia[i] != NULL) {
			std::cout << "Materia[" << i << "]: [" << this->_materia[i]->getType() << "]" << std::endl;
		}
	}
}

/*
** Public member functions
*/
void			MateriaSource::learnMateria(AMateria* materia) {

	for (int i = 0; i < 4; i++) {
		
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
			break ;
		}
	}
}

AMateria*		MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++) {

		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}

/*
** Private member functions
*/
void			MateriaSource::_deleteMateria(void) {

	for (int i = 0; i < 4; i++) {

		if (this->_materia[i] != NULL) {
			delete this->_materia[i];
		}
	}
}

void			MateriaSource::_copyMateria(MateriaSource const & src) {

	for (int i = 0; i < 4; i++) {

		if (src._materia[i] != NULL) {
			this->_materia[i] = src._materia[i]->clone();
		}
	}
}
