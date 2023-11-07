#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main() {
	// Creating an instance of ShrubberyCreationForm
	ShrubberyCreationForm shrubbery("home");

	// Creating an instance of RobotomyRequestForm
	RobotomyRequestForm robotomy("Bender");

	// Creating an instance of PresidentialPardonForm
	PresidentialPardonForm pardon("Zaphod Beeblebrox");

	// Testing the execute function of ShrubberyCreationForm
	shrubbery.execute(Bureaucrat("Bob", 1));

	// Testing the execute function of RobotomyRequestForm
	robotomy.execute(Bureaucrat("Alice", 1));

	// Testing the execute function of PresidentialPardonForm
	pardon.execute(Bureaucrat("Charlie", 1));

	return 0;
}
