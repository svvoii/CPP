#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main() {

	// Creating a bunch of Bureaucrats
	Bureaucrat bob("Bob", 150);
	Bureaucrat bill("Bill", 1);
	Bureaucrat alice("Alice", 1);
	Bureaucrat charlie("Charlie", 1);

	// Creating instances of the AForm derived classes
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Zaphod Beeblebrox");

	// Testing the execute function with unsigned forms with each bureaucrat
	std::cout << BLUE << "< Testing the execute function with unsigned forms with each bureaucrat >" << RESET << std::endl;
	try {
		shrubbery.execute(bob);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		shrubbery.execute(bill);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		robotomy.execute(alice);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		pardon.execute(charlie);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Trying to signing the forms
	std::cout << BLUE << "< Trying to signing the forms >" << RESET << std::endl;
	try {
		bob.signForm(shrubbery);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bill.signForm(shrubbery);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		alice.signForm(robotomy);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		charlie.signForm(pardon);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Trying to execute the forms after signing them
	std::cout << BLUE << "< Trying to execute the forms after signing them >" << RESET << std::endl;
	try {
		shrubbery.execute(bob);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		shrubbery.execute(bill);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		robotomy.execute(alice);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		pardon.execute(charlie);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
