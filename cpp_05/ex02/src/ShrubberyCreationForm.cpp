/*
** Implementation if the `ShrubberyCreationForm` class which inherits from `AForm`.
*/

#include "../includes/ShrubberyCreationForm.hpp"

/*
** Constructor:
** The constructor must initialize the form with a name, a grade to sign and a grade to execute.
** The grades must never be greater than 150 or less than 1.
** If it does, throw an exception.
*/
ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm("default", 145, 137),
	_target("default") {

	std::cout << CYAN << "\t< ShrubberyCreationForm default constructor called >" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target) {

	std::cout << CYAN << "\t< ShrubberyCreationForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
}

/*
** Copy constructor:
*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : 
	AForm(copy.getName(), 
	copy.getGradeToSign(), 
	copy.getGradeToExecute()) {

	if (this != &copy) {
		*this = copy;
		_target = copy._target;
	}
	std::cout << CYAN << "\t< ShrubberyCreationForm copy constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
}

/*
** Destructor:
*/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << RED << "\t< ShrubberyCreationForm destructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
}

/*
** Assignment operator overload:
*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {

	std::cout << CYAN << "\t< ShrubberyCreationForm assignment operator called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	return *this;
}

/*
** Public member functions:
*/
void	ShrubberyCreationForm::executeAction(void) const {

	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (ofs.is_open()) {
		ofs << "      /\\      " << std::endl;
		ofs << "     /\\*\\     " << std::endl;
		ofs << "    /\\O\\*\\    " << std::endl;
		ofs << "   /*/\\/\\/\\   " << std::endl;
		ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
		ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "    \\====/    " << std::endl;
		ofs << "     \\__/     " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "    \\====/    " << std::endl;
		ofs << "     \\__/     " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "    \\====/    " << std::endl;
		ofs << "     \\__/     " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs.close();
	}
	else {
		std::cout << RED << "\t< ShrubberyCreationForm >" << RESET;
		std::cout << " could not open file: [" << this->_target << "_shrubbery]" << std::endl;
	}

	return ;
}
