/*
** Definition of Bureaucrat class.
**
** `Bureaucrat` class has constant atributtes:
** `name` - name of the bureaucrat
** `grade` - grade of the bureaucrat, which ranges from 
** 1 (as highest) to 150 (as lowest).
**
** Any attempt to create a bureaucrat with an invalid grade must throw
** an exception `GradeTooHighException` or `GradeTooLowException`.
** 
** `Bureaucrat` class has methods:
** `getName` - returns the name of the bureaucrat
** `getGrade` - returns the grade of the bureaucrat
** `incrementGrade` - increments the grade of the bureaucrat
** `decrementGrade` - decrements the grade of the bureaucrat
** If the grade is out of range, the function must throw same exception
** as in the constructor.
**
** `Bureaucrat` class has operators:
** `<<` - overload operator `<<` to print `Bureaucrat` class
** as follows: `<name>, bureaucrat grade <grade>`.
*/

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {

	std::cout << CYAN << "\t< Bureaucrat default constructor called >" << RESET << std::endl;
}

/*
** Constructor:
** The constructor must initialize the bureaucrat with a name and a grade.
** The grade must never be greater than 150 or less than 1.
** If it does, throw an exception.
*/
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {

	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade = grade;
	}

	std::cout << CYAN << "\t< Bureaucrat constructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
}

/*
** Copy constructor:
*/
Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name) {

	if (this != &copy) {
		*this = copy;
	}
	std::cout << CYAN << "\t< Bureaucrat copy constructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
}

/*
** Destructor:
*/
Bureaucrat::~Bureaucrat() {

	std::cout << RED << "\t< Bureaucrat destructor called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
}

/*
** Assignment operator overload:
** `const_cast` is used to cast away the constness of the `_name` attribute
** to be able to assign the value of the `copy._name` to it.
** Not a good practice, it is better to design the class in a different way.
*/
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {

	if (this != &copy) {
		//const_cast<std::string&>(this->_name) = copy._name;
		this->_grade = copy._grade;
	}
	std::cout << CYAN << "\t< Bureaucrat assignment operator called >" << RESET;
	std::cout << " name: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;

	return (*this);
}

/*
** Getter functions:
*/
std::string const	&Bureaucrat::getName() const {

	return (this->_name);
}

int	Bureaucrat::getGrade() const {

	return (this->_grade);
}

/*
** Increment and decrement functions:
*/
void	Bureaucrat::incrementGrade() {

	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		this->_grade--;
	}

	std::cout << GREEN << "\t< grade increment called >" << RESET;
	std::cout << " for: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
	std::cout << std::endl;
}

void	Bureaucrat::decrementGrade() {

	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade++;
	}

	std::cout << GREEN << "\t< grade decrement called >" << RESET;
	std::cout << " for: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
	std::cout << std::endl;
}

/*
** New member function. It takes a reference to a `Form` and tries to sign it,
** if the bureaucrat's grade is high enough. If not, it prints a message
** indicating that the bureaucrat can't sign the form due to low grade.
*/
void	Bureaucrat::signForm(Form &form) {

	if (this->_grade <= form.getGradeToSign()) {
		form.beSigned(*this);
		std::cout << GREEN << "\t< form signed >" << RESET;
		std::cout << " by: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << RED << "\t< form not signed >" << RESET;
		std::cout << " by: [" << this->_name << "], grade: [" << this->_grade << "]" << std::endl;
		std::cout << std::endl;
	}
}

/*
** GradeTooHighException class:
*/
const char *Bureaucrat::GradeTooHighException::what() const throw() {

	return RED "Grade is invalid or already the highest!\n" RESET;
}

/*
** GradeTooLowException class:
*/
const char *Bureaucrat::GradeTooLowException::what() const throw() {

	return RED "Grade is invalid or already the lowest!\n" RESET;
}

/*
** Overload operator `<<` to print `Bureaucrat` class as follows:
** `<name>, bureaucrat grade <grade>`.
*/
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {

	std::cout << BLUE << "\t< output stream called >" << RESET << std::endl;

	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	std::cout << std::endl;

	return (out);
}
