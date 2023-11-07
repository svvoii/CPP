/*
** This is the definition of the another derived class from AForm.
*/

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm("PresidentialPardonForm", 25, 5),
	_target("default") {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : 
	AForm("PresidentialPardonForm", 25, 5), 
	_target(target) {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : 
	AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {

	*this = copy;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
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

	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
