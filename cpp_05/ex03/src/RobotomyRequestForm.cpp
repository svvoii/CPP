/*
** This is the definition of the another derived class from AForm.
*/

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("RobotomyRequestForm", 72, 45) {

	std::cout << CYAN << "\t< RobotomyRequestForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : 
	AForm("RobotomyRequestForm", 72, 45), 
	_target(target) {

	std::cout << CYAN << "\t< RobotomyRequestForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;

	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : 
	AForm(copy.getName(), 
	copy.getGradeToSign(), 
	copy.getGradeToExecute()) {

	this->_target = copy._target;
	*this = copy;

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	std::cout << RED << "\t< RobotomyRequestForm destructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;

	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {

	if (this != &copy) {
		_target = copy._target;
	}
	return *this;
}

/*
** This will be the implementation of the `executeAction` method.
*/
void	RobotomyRequestForm::executeAction(void) const {

	std::srand(std::time(NULL));
	int random = std::rand() % 2;

	std::cout << MAGENTA << "Bzzz-z-z-z-... Bzzz-z-z-z-... (LOUD DRILLING NOISES)\t" << RESET;

	if (random == 0) {
		std::cout << "Robotomization of [" << _target << "] was successful!" << std::endl;
	}
	else {
		std::cout << "Robotomization of [" << _target << "] failed!" << std::endl;
	}
	std::cout << std::endl;
}
