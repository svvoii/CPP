/*
** This class will be the last one in these series of exercises
** with bureaucracy and forms. 
** This is a stand alone class, it will not inherit from any other
** class. It will be:
** `Intern` class, that:
** dont have any attributes like (name, grade, target, etc),
** but it has a method:
** `AForm *makeForm(std::string const &formName, std::string const &target);`
** This method will return a pointer to a Form object (whose name is passed).
** So, 
** `&formName` will be the name of the form to be created.
** `&target` will be the target of the form to be created.
** The method will print a message when the form is created:
** `Intern creates <formName> form`.
** If the form name passed is not one of the three forms that we have:
** `ShrubberyCreationForm`, `RobotomyRequestForm` or `PresidentialPardonForm`,
** it will print explicit error message:
** `Intern cannot create <formName>, form is not valid`.
*/

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

enum FormType {
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	FORM_TYPE_MAX
};

class Intern {

	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		Intern &operator=(Intern const &copy);

		AForm *makeForm(std::string const &formName, std::string const &target);

};

#endif
