#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>
# include <string>

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

		LevelFunctionPair _level_to_f[MAX_LEVELS];

	public:
	
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif

/*
** We also can use the following syntax to declare a pointer to a member function:
** `typedef void	(Harl::*f_ptr)(void);` - right before the struct dfinition.
**
** in this case we can use `f_ptr` instead of `void	(Harl::*function)(void);`:
** `f_ptr	function;` this will be a pointer to a member function of class `Harl`.
*/
