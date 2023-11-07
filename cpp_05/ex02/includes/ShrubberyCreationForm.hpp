/*
** This is a new, class which inherits from AForm.
**
** This class is responsible for creating a file
** with ASCII art of a tree inside the file.
** Requirements for successful creation are:
** `grade` to sign the form is 145 or lower
** `grade` to execute the form is 137 or lower
** It shall create a file called `target`_shrubbery
** in the parent directory.
*/

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    private:
        std::string		    _target;
		// These are not needed, since they are inherited from AForm
        //static int const	_minGradeToSign = 145;
        //static int const	_minGradeToExecute = 137;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

        //std::string const	&getTarget() const;

        void				executeAction(void) const;
};

#endif
