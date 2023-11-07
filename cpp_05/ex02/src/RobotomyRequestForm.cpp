/*
** This is the definition of the another derived class from AForm.
*/

#include "../includes/RobotomyReruestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
	*this = copy;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
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

	std::cout << "Bzzz-z-z-z-... Bzzz-z-z-z-... (LOUD DRILLING NOISES)" << std::endl;

	if (random == 0) {
		std::cout << "Robotomization of [" << _target << "] was successful!" << std::endl;
	}
	else {
		std::cout << "Robotomization of [" << _target << "] failed!" << std::endl;
	}
}
