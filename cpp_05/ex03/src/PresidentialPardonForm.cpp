/*
** This is the definition of the another derived class from AForm.
*/

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm("PresidentialPardonForm", 25, 5),
	_target("default") {

	std::cout << CYAN << "\t< PresidentialPardonForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : 
	AForm("PresidentialPardonForm", 25, 5), 
	_target(target) {

	std::cout << CYAN << "\t< PresidentialPardonForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : 
	AForm(copy.getName(), 
	copy.getGradeToSign(), 
	copy.getGradeToExecute()) {

	*this = copy;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	std::cout << RED << "\t< PresidentialPardonForm destructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;

	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {

	if (this != &copy) {
		_target = copy._target;
	}
	return *this;
}

/*
** This will be the implementation of the `executeAction` method.
*/
void	PresidentialPardonForm::executeAction(void) const {

	std::cout << MAGENTA << _target << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
	std::cout << std::endl;
}
