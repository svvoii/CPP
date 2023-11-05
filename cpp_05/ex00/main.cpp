#include "includes/Bureaucrat.hpp"

/*
** Here we are testing the `Bureaucrat` class and all its methods.
*/

int main() {

	std::cout << "Creating Bureaucrat 'Bob', with grade: 1);" << std::endl;
    Bureaucrat b1("Bob", 1);
	std::cout << std::endl;

	std::cout << "Creating Bureaucrat 'Margaret', with grade: 150" << std::endl;
    Bureaucrat b2("Margaret", 150);
	std::cout << std::endl;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try {
		std::cout << "Trying to create Bureaucrat 'Jack', with grade: 0);" << std::endl;
        Bureaucrat b3("Jack", 0);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
		std::cout << "Trying to create Bureaucrat 'Jill', with grade: 151);" << std::endl;
        Bureaucrat b4("Jill", 151);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	try {
		std::cout << "Trying to promote [" << b1.getName() << "]" << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to demote [" << b2.getName() << "]" << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    try {
		std::cout << "Trying to promote [" << b2.getName() << "]" << std::endl;
        b2.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
		std::cout << "Trying to demote [" << b1.getName() << "]" << std::endl;
        b1.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
