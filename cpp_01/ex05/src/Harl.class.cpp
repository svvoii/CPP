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

	std::cout << "[DEBUG] message:" << std::endl;
	std::cout << "\"" << DEBUG_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_info(void) {

	std::cout << "[INFO] message:" << std::endl;
	std::cout << "\"" << INFO_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_warning(void) {

	std::cout << "[WARNING] message:" << std::endl;
	std::cout << "\"" << WARNING_MSG << "\"" << std::endl << std::endl;
}

void	Harl::_error(void) {

	std::cout << "[ERROR] message:" << std::endl;
	std::cout << "\"" << ERROR_MSG << "\"" << std::endl << std::endl;
}

/*
** In this function we first checks if the level is valid by checking 
** if the `level` is present in the vector `_level_to_f` as a key.
** If it is, it calls the function that is paired with that `level`.
** Otherwise, it prints an error message.
*/
#include <algorithm>

void	Harl::complain(std::string level) {

	for (size_t i = 0; i < MAX_LEVELS; i++) {

		if (_level_to_f[i].level == level) {
			(this->*(_level_to_f[i].function))();
			return ;
		}
	}
	std::cout << "Invalid level. Try again." << std::endl;
	std::cout << "Usage: DEBUG, INFO, WARNING, ERROR or EXIT\n" << std::endl;
}

/* ******************************************************************* */

/*
** In this constructor, we initialize the map `_level_to_f`
** to point to the appropriate member function given a level.
Harl::Harl() {
	
	_level_to_f["DEBUG"] = &Harl::_debug;
	_level_to_f["INFO"] = &Harl::_info;
	_level_to_f["WARNING"] = &Harl::_warning;
	_level_to_f["ERROR"] = &Harl::_error;

	return;
}
*/

/*
** This access the map `_level_to_f` using the `level` as a key
** and calls the function that is mapped to that key.
void	Harl::complain(std::string level) {
	if (_level_to_f.count(level) > 0 ) {
		(this->*_level_to_f[level])();
	}
	else {
		std::cout << "Invalid level. Try again. ";
		std::cout << "Usage: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
}
*/

/*
** In this version we first declare an array of pointers to member functions,
** initialize it with the appropriate member functions.
** Then create an array of strings that contains the levels and then loop through
** the array to find the appropriate member function to call it given string level.
**
void	Harl::complain(std::string level) {

	// using a pointer to member function to call the appropriate member function
	typedef void (Harl::*f_ptr)(void);

	f_ptr f[4];

	f[0] = &Harl::_debug;
	f[1] = &Harl::_info;
	f[2] = &Harl::_warning;
	f[3] = &Harl::_error;

	// One line implementation:
	// f_ptr f[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*f[i])();
			return;
		}
	}
	std::cout << "Invalid level\n";
	return;
}
*/
