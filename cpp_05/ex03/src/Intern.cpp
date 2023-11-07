/*
** Definition of the Intern class
*/

#include "../includes/Intern.hpp"

/*
** Intern default constructor
*/
Intern::Intern(void) {

	std::cout << CYAN << "\t< Intern default constructor called >" << RESET << std::endl;
	std::cout << std::endl;

	return ;
}

/*
** Intern copy constructor
*/
Intern::Intern(Intern const &copy) {

	std::cout << CYAN << "\t< Intern copy constructor called >" << RESET << std::endl;
	std::cout << std::endl;

	*this = copy;

	return ;
}

/*
** Intern destructor
*/
Intern::~Intern(void) {

	std::cout << RED << "\t< Intern destructor called >" << RESET << std::endl;
	std::cout << std::endl;

	return ;
}

/*
** Intern assignation operator overload
*/
Intern &Intern::operator=(Intern const &copy) {

	if (this != &copy) {
		;
	}
	return *this;
}

/*
** This method will return a pointer to a Form object (whose name is passed).
** So,
** `&formName` will be the name of the form to be created.
** `&target` will be the target of the form to be created.
** The method will print a message when the form is created:
** `Intern creates <formName> form`.
** If the form name passed is not one of the three forms that we have:
** `ShrubberyCreationForm`, `RobotomyRequestForm` or `PresidentialPardonForm`,
** it will print explicit error message:
** `Intern cannot create <formName>, form is not valid`.
*/

struct FormCreator {
	std::string const formName;
	AForm *(*createFormFunction)(std::string const &target);
};

AForm *createShrubberyCreationForm(std::string const &target) { 
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {

	FormCreator validForms[FORM_TYPE_MAX] = {
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};

	for (int i = 0; i < FORM_TYPE_MAX; i++) {
		if (validForms[i].formName == formName) {
			std::cout << GREEN << "Intern creates [" << formName << "] form" << RESET << std::endl;
			std::cout << std::endl;

			return validForms[i].createFormFunction(target);
		}
	}

	std::cout << RED << "Intern cannot create [" << formName << "], form is not valid" << RESET << std::endl;
	std::cout << std::endl;

	return NULL;
}

