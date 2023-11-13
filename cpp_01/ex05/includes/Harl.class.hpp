#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>
# include <string>
# include <limits>

# define MAX_LEVELS 4

# define DEBUG_MSG "I love having extra salad for my 7XL-double-cheese-triple-pickle-special-sauce veggie burger. I really do!"
# define INFO_MSG "I cant believe adding extra salad costs more money. You didn't put enough salad in my burger! If you did, I wouldn't be asking for more!"
# define WARNING_MSG "I think I deserve to have some extra salad for free. I've been comming for years whereas you started working here since last month."
# define ERROR_MSG "This is unacceptable! I want to spark to the manager now."

class Harl;

struct LevelFunctionPair {
	std::string	level;
	void		(Harl::*function)(void);
};

/*
** `(Harl::*function)(void)` will be a pointer to a member function of class `Harl`
** `LevelFunctionPair` will be used to store the string level
** and the pointer to the respective member function of class `Harl`
** This will work as key-value pair.
*/

class Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

		LevelFunctionPair _level_to_f[4];

	public:
	
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif


/*
** This is to illustrate how can we use std::map or std::vector to store
** a string and a pointer to a member function of a class as a key-value pair.
**
# include <vector>
# include <map>

class Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

		// the following statement allows to use a pointer to any member function above
		typedef void (Harl::*f_ptr)(void);

		// the folowing map maps a string to a pointer to a member function
		//std::map<std::string, f_ptr> _level_to_f;

		// another way to do it is to use a vector of pairs, 
		// each pair containing a string and a pointer to a member function4
		std::vector<std::pair<std::string, f_ptr> > _level_to_f;

	public:
	
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif

** `void (Harl::*f_ptr)(void)` is a pointer to a member function of the class `Harl`
** The syntax for it is something new.
** A `typedef` defines a new type called `f_ptr` which is a pointer to 
** a member function of this class, that takes no arguments and returns nothing.
**
** `typedef` statement, in this case, provides a convenient way to declare 
** and use pointers to member functions of the class.
**
** Using a pointer to a member function can be useful when you want to
** pass a function as an argument to another function.
** Or store a function pointer in a data structure.
**
** This allows to call teh appropriate member function on a specific instance
** of the class, rather that on the class itself.
*/