#include "../includes/Harl.class.hpp"

/*
** In this constructor, we initialize the vector `_level_to_f`
** to point to the appropriate member function given a level.
*/
Harl::Harl() {
	
	_level_to_f[0].level = "DEBUG";
	_level_to_f[0].function = &Harl::_debug;

	_level_to_f[1].level = "INFO";
	_level_to_f[1].function = &Harl::_info;

	_level_to_f[2].level = "WARNING";
	_level_to_f[2].function = &Harl::_warning;

	_level_to_f[3].level = "ERROR";
	_level_to_f[3].function = &Harl::_error;

	return;
}

Harl::~Harl() {
	return;
}

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]:" << std::endl;
	std::cout << "\"" << DEBUG_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]:" << std::endl;
	std::cout << "\"" << INFO_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "[ WARNING ]:" << std::endl;
	std::cout << "\"" << WARNING_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]:" << std::endl;
	std::cout << "\"" << ERROR_MSG << "\"" << std::endl << std::endl;
}

/*
** In this function `case` statement is used to call the appropriate function
** and all the functions which follow it.
*/

void	Harl::complain(std::string level) {

	for (size_t i = 0; i < MAX_LEVELS; i++) {
		
		if (_level_to_f[i].level == level) {
			
			switch (i) {
				case 0:
					(this->*_level_to_f[0].function)();
					(this->*_level_to_f[1].function)();
					(this->*_level_to_f[2].function)();
					(this->*_level_to_f[3].function)();
					break ;
				case 1:
					(this->*_level_to_f[1].function)();
					(this->*_level_to_f[2].function)();
					(this->*_level_to_f[3].function)();
					break ;
				case 2:
					(this->*_level_to_f[2].function)();
					(this->*_level_to_f[3].function)();
					break ;
				case 3:
					(this->*_level_to_f[3].function)();
					break ;
				default:
					break ;
			}

			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}


