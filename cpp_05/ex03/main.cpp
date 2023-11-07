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

	std::cout << "Executing forms:" << std::endl;
	std::cout << std::endl;

	rrf->executeAction();
	scf->executeAction();
	ppf->executeAction();
	unknown->executeAction();

	std::cout << std::endl;

	delete rrf;
	delete scf;
	delete ppf;
	//delete unknown;

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
