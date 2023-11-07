/*
** Changing the `Form` class into an abstract class:
**
** `AForm` will be a base form class for all the form classes.
**
** We also added another method to this base class:
** `execute(Bureaucrat const &executor) const` which will be used
** to execute the form. The method will check whether the form is
** signed and whether the executor's grade is high enough to execute
** the form. Otherwise, it will throw an exception.
**
*/

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(void);
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		//~AForm(void);
		virtual ~AForm(void);

		AForm &operator=(AForm const &copy);

		std::string const	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat const &bureaucrat);

		// Adding new, execute methods
		void				execute(Bureaucrat const &executor) const;
		// This method will be overridden by derived classes
		virtual void		executeAction() const = 0;

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

		// Fresh excdeption for NOT signed form
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif

/*
** About the `execute` method:
** `virtual void executeAction() const;`
** `virtual` - means that this method is virtual and will be overridden
** by the derived classes.
** `= 0` - this syntax means that this method is a pure virtual method.
**
** `Pure virtual methods` are virtual methods that are declared in the base
** class but not defined. They are used to make the base class abstract.
** Every class that inherits from an abstract class must implement the pure
** virtual methods, unless it is also an abstract class.
*/
