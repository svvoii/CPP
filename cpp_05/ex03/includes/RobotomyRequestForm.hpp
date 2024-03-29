/*
** This class is responsible for making some drilling noises
** and telling us whether the robotization was successful or not.
** Requirements for successful robotization are:
** `grade` to sign the form is 72 or lower
** `grade` to execute the form is 45 or lower
** It shall inform that `target` has been robotomized successfully
** 50% of the time. 
** Otherwise, it shall inform that the robotomization has failed.
*/

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {

    private:
        std::string		    _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

        void				executeAction(void) const;
};

#endif
