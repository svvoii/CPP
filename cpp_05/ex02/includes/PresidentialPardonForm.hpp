/*
** The PresidentialPardonForm class, inherits from AForm.
** 
** Requirements for successful creation are:
** `grade` to sign the form is 25 or lower
** `grade` to execute the form is 5 or lower
** It shall inform that `target` has been pardoned by
** Zafod Beeblebrox.
*/

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string		    _target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

        //std::string const	&getTarget() const;

        void				executeAction() const;
};

#endif
