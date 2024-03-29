/*
** Bellow we have simple `Bureaucrat` class in a canonical form.
**
** The following method was added in the previous exercise:
** `signForm` - it takes a reference to a `Form` and tries to sign it,
** if the bureaucrat's grade is high enough. If not, it prints a message
** indicating that the bureaucrat can't sign the form due to low grade.
**
** In this exercise we will add another method:
** `executeForm(AForm const &form)` - it will take a reference to a `Form`
** and try to execute it, if the bureaucrat's grade is high enough. 
** If not, it prints an explicit error message indicating that 
** the bureaucrat can't execute the form due to low grade.
*/

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class AForm;

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
	 	Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &copy);

		std::string const	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm &form);
		
		// New member function
		void				executeForm(AForm const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
