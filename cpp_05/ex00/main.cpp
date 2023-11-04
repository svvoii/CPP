#include "includes/Bureaucrat.hpp"

int main() {

    Bureaucrat b1("Bob", 1);
    Bureaucrat b2("Margaret", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try {
        Bureaucrat b3("Jack", 0);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Jill", 151);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	try {
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    try {
        b2.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        b1.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
