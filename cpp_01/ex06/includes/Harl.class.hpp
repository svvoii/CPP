#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

# define DEBUG_MSG "I love having extra salad for my 7XL-double-cheese-triple-pickle-special-sauce veggie burger. I really do!"
# define INFO_MSG "I cant believe adding extra salad costs more money. You didn't put enough salad in my burger! If you did, I wouldn't be asking for more!"
# define WARNING_MSG "I think I deserve to have some extra salad for free. I've been comming for years whereas you started working here since last month."
# define ERROR_MSG "This is unacceptable! I want to spark to the manager now."

class Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

		// the following statement allows to use a pointer to any member function above
		typedef void (Harl::*f_ptr)(void);

		std::vector<std::pair<std::string, f_ptr> > _level_to_f;

	public:
	
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif
