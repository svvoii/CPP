/*
** Implementation of the `Form` class.
*/

#include "../includes/Form.hpp"

Form::Form(void) : 
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
Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
	else {
		std::cout << CYAN << "\t< Form constructor called >" << RESET;
		std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
	}
}

/*
** Copy constructor:
*/
Form::Form(Form const &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {

	if (this != &copy) {
		*this = copy;
	}
	std::cout << CYAN << "\t< Form copy constructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
}

/*
** Destructor:
*/
Form::~Form(void) {

	std::cout << RED << "\t< Form destructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade to sign: [" << this->_gradeToSign << "], grade to execute: [" << this->_gradeToExecute << "]" << std::endl;
}

/*
** Assignment operator overload:
*/
Form &Form::operator=(Form const &copy) {

	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

/*
** Public member functions:
*/
std::string const	&Form::getName(void) const {

	return this->_name;
}

bool	Form::getIsSigned(void) const {

	return this->_isSigned;
}

int	Form::getGradeToSign(void) const {

	return this->_gradeToSign;
}

int	Form::getGradeToExecute(void) const {

	return this->_gradeToExecute;
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw Form::GradeTooLowException();
	}
	else {
		this->_isSigned = true;
	}
}

/*
** Exception classes:
*/
const char *Form::GradeTooHighException::what() const throw() {

	return RED "Form: Grade too high" RESET;
}

const char *Form::GradeTooLowException::what() const throw() {

	return RED "Form: Grade too low" RESET;
}

/*
** Overload of the `<<` operator:
*/
std::ostream &operator<<(std::ostream &out, Form const &form) {

	out << "Form: [" << form.getName() << "], is signed: [" << form.getIsSigned() << "], grade to sign: [" << form.getGradeToSign() << "], grade to execute: [" << form.getGradeToExecute() << "]" << std::endl;
	return out;
}
