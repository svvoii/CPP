/*
** Implementation of the `Form` class.
*/

#include "../includes/AForm.hpp"

AForm::AForm(void) : 
	_name("default"), 
	_isSigned(false), 
	_gradeToSign(150), 
	_gradeToExecute(150) {

	std::cout << CYAN << "\t< Form default constructor called >" << RESET << std::endl;
}

/*
** Constructor:
** The constructor must initialize the form with a name, a grade to sign and a grade to execute.
** The grades must never be greater than 150 or less than 1.
** If it does, throw an exception.
*/
AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : 
	_name(name), 
	_isSigned(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute) {

	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::cout << CYAN << "\t< Form constructor called >" << RESET;
		std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
	}
}

/*
** Copy constructor:
*/
AForm::AForm(AForm const &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {

	if (this != &copy) {
		*this = copy;
	}
	std::cout << CYAN << "\t< Form copy constructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
}

/*
** Destructor:
*/
AForm::~AForm(void) {

	std::cout << RED << "\t< Form destructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
}

/*
** Assignment operator overload:
*/
AForm &AForm::operator=(AForm const &copy) {

	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

/*
** Public member functions:
*/
std::string const	&AForm::getName(void) const {

	return this->_name;
}

bool	AForm::getIsSigned(void) const {

	return this->_isSigned;
}

int	AForm::getGradeToSign(void) const {

	return this->_gradeToSign;
}

int	AForm::getGradeToExecute(void) const {

	return this->_gradeToExecute;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	else {
		this->_isSigned = true;
	}
}

/*
** New member function where we first check if the form is signed 
** and whether the executor's grade is high enough to execute the form. 
** Otherwise, it will throw an appropriate exception.
*/
void	AForm::execute(Bureaucrat const &executor) const {

	if (this->_isSigned == false) {
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() > this->_gradeToExecute) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "Form [" << this->_name << "] is signed and the executor's grade: [";
	std::cout << executor.getGrade() << "] is OK to execute the form. Passing to execution.." << std::endl;

	// This is where we call the execute function of the derived class
	this->executeAction();
}

/*
** Exception classes:
*/
const char *AForm::GradeTooHighException::what() const throw() {

	return RED "Form: Grade too high" RESET;
}

const char *AForm::GradeTooLowException::what() const throw() {

	return RED "Form: Grade too low" RESET;
}

const char *AForm::FormNotSignedException::what() const throw() {

	return RED "Form: Not signed, cannot execute" RESET;
}

/*
** Overload of the `<<` operator:
*/
std::ostream &operator<<(std::ostream &out, AForm const &form) {

	out << "Form: [" << form.getName() << "], is signed: [" << form.getIsSigned() << "], grade to sign: [" << form.getGradeToSign() << "], grade to execute: [" << form.getGradeToExecute() << "]" << std::endl;
	return out;
}
