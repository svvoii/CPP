/*
** This is the main function that will test the Intern class.
** It will create an Intern object, and then it will call the
** `makeForm` method with different form names.
** It will also call the `executeForm` method with the forms
** that were created.
*/

#include "includes/Intern.hpp"

int	main(void) {

	Intern someRandomIntern;
	AForm *rrf;
	AForm *scf;
	AForm *ppf;
	AForm *unknown;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Zafod Beeblebrox");
	unknown = someRandomIntern.makeForm("unknown", "unknown");

	std::cout << std::endl;
	std::cout << "Executing forms:" << std::endl << std::endl;

	AForm *forms[FORM_TYPE_MAX + 1] = { rrf, scf, ppf, unknown };
	for (int i = 0; i <= FORM_TYPE_MAX; i++) {
		try {
			if (forms[i])
				forms[i]->executeAction();
			else
				throw std::runtime_error(" ...no such form");
		}
		catch (std::exception &e) {
			std::cout << RED << "Error ececuting action" << e.what() << RESET << std::endl << std::endl;
		}
	}

	for (int i = 0; i < FORM_TYPE_MAX; i++) {
		if (forms[i])
			delete forms[i];
	}

	std::cout << std::endl;

	return 0;
}

/*
** Expected output:
**
** $> clang++ -Wall -Wextra -Werror *.cpp -o intern
** $> ./intern
** Intern creates robotomy request form
** Intern creates shrubbery creation form
** Intern creates presidential pardon form
** Intern cannot create unknown, form is not valid
**
** Executing forms:
**
** Bender has been robotomized
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
** Form is not signed
** home has been pardoned by Zafod Beeblebrox.
**
** $>
*/
