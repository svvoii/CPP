/*
** Adding another class to our Bureaucrat series of classes.
** `Form` class will be a class that will be signed by a `Bureaucrat`.
** Private atributes:
** `name` - constant string, that will be used to identify the form.
** `isSigned` - boolean, indicating if the form is signed or not.
** `gradeToSign` - integer, indicating the grade required to sign the form.
** `gradeToExecute` - integer, indicating the grade required to execute the form.
**
** The grades in the `Form` follow the same rules as in the `Bureaucrat` class.
** If the grade is out of bounds, throw an exception.
**
** Public methods:
** `getName` - returns the name of the form.
** `getIsSigned` - returns the boolean indicating if the form is signed or not.
** `getGradeToSign` - returns the grade required to sign the form.
** `getGradeToExecute` - returns the grade required to execute the form.
** `beSigned` - takes a reference to a `Bureaucrat` and signs the form 
** if the bureaucrat's grade is high enough. If not, throw same exception.
**
** `Form` also has an overload `<<` operator, that prints all the form's attributes. 
*/

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(void);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		~Form();

		Form &operator=(Form const &copy);

		std::string const	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
