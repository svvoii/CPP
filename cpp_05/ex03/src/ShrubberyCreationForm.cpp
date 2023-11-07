/*
** Implementation if the `ShrubberyCreationForm` class which inherits from `AForm`.
*/

#include "../includes/ShrubberyCreationForm.hpp"

/*
** Constructor:
** The constructor must initialize the form with a name, a grade to sign and a grade to execute.
** The grades must never be greater than 150 or less than 1.
** If it does, throw an exception.
*/
ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm("default", 145, 137),
	_target("default") {

	std::cout << CYAN << "\t< ShrubberyCreationForm default constructor called >" << RESET << std::endl;
	std::cout << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target) {

	std::cout << CYAN << "\t< ShrubberyCreationForm constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;
}

/*
** Copy constructor:
*/
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : 
	AForm(copy.getName(), 
	copy.getGradeToSign(), 
	copy.getGradeToExecute()) {

	if (this != &copy) {
		*this = copy;
		_target = copy._target;
	}
	std::cout << CYAN << "\t< ShrubberyCreationForm copy constructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	std::cout << std::endl;
}

/*
** Destructor:
*/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << RED << "\t< ShrubberyCreationForm destructor called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
}

/*
** Assignment operator overload:
*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {

	if (this != &copy) {
		_target = copy._target;
	}
	std::cout << CYAN << "\t< ShrubberyCreationForm assignment operator called >" << RESET;
	std::cout << " name: [" << AForm::getName() << "], target: [" << this->_target << "]" << std::endl;
	return *this;
}

/*
** Public member functions:
*/
void	ShrubberyCreationForm::executeAction(void) const {

	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (ofs.is_open()) {
		ofs << "" << std::endl;
		ofs << "                                  .t:. " << std::endl;
		ofs << "                                  ;@;. " << std::endl;
		ofs << "                                 ;;;%% " << std::endl;
		ofs << "                                 ::;:: " << std::endl;
		ofs << "                               .%tX S%%. " << std::endl;
		ofs << "                                 . tt... " << std::endl;
		ofs << "                              tSX%S@SSS%S " << std::endl;
		ofs << "                            .%t%%t%%t%%%tS: " << std::endl;
		ofs << "                             ;:::;:;::;:::. " << std::endl;
		ofs << "                           t%S%%S%%S%%S%SS%% " << std::endl;
		ofs << "                            ...:.....:..... " << std::endl;
		ofs << "                            .%tt%t%%tX Xt%: " << std::endl;
		ofs << "                           ..:.:...:..SS;:.. " << std::endl;
		ofs << "                           .:::::::::;t::::: " << std::endl;
		ofs << "                         .%t%%t%Xt%%t%%%%%%t%: " << std::endl;
		ofs << "                         .;::;:tt%:;::;::;:;;. " << std::endl;
		ofs << "                        ;t%t%%tt%t%%t%ttt%ttt%tt " << std::endl;
		ofs << "                       .  .    . ..  ..  .   . . " << std::endl;
		ofs << "                      .SSSS%@8%%S%X8@SS%SS%SS%SS; " << std::endl;
		ofs << "                     ttSt%%t;t%%%%%S%%%%%%%%%%%%t% " << std::endl;
		ofs << "                     .:::::;:::::::::::::;.;:::::: " << std::endl;
		ofs << "                  t%S%%S%%S%%S%%S%%S%SS%%S%%S%%S%SS%% " << std::endl;
		ofs << "                   .. .:..:..::;;.:......:..:.:..  . " << std::endl;
		ofs << "                      .%tt%tt%@8:tt%t%%t%%t%%tt%: " << std::endl;
		ofs << "                     ...:.:.. :;:..:.:........:... " << std::endl;
		ofs << "                     ::::::::;::::::@. .:;:::::::: " << std::endl;
		ofs << "                   .%t%%t%%t%%t%%t%%:.%%t%%tt;%%t%%: " << std::endl;
		ofs << "                    ;:;:::;::;::;::;:;::;::;8St;:;;. " << std::endl;
		ofs << "                  ;%%88X%t%t%%t%%t%%t%%t%%t%S%%%t%%t% " << std::endl;
		ofs << "                 .   :t: .   .   .          .. :.    . " << std::endl;
		ofs << "                .SS%S%SSS%X%SS%SSS8X%SX%SS%SX%S8S@S%SS; " << std::endl;
		ofs << "             .S%%%%%S%%%%%%t%St%S%S%%%%%%%%%%%%S%%St%StS%: " << std::endl;
		ofs << "              :::;:::::::::;:::::::::::::::::::::::::::::. " << std::endl;
		ofs << "                    t:;;;;;:;;;;;;;;;;;;;;;;;;;;;;;.. " << std::endl;
		ofs << "                  ................................:.. " << std::endl;
		ofs << "                  ;t%tX8Xt%tt%tt%t%%tt%tt%tt%t%%t%tt% " << std::endl;
		ofs << "                 ::::::X;::::::::..::::::::::.:::::.::. " << std::endl;
		ofs << "                .;;;;;;;;:;;;;;;;S8;;;;:;;:;;88::;;;;;. " << std::endl;
		ofs << "               tt%%t%%t%t%%t%%t%%%%%t%%%t%%%%t;%%%%t%%t% " << std::endl;
		ofs << "               ::;::;::;::;::;::;::;::;:;;::;:;;::;:;::; " << std::endl;
		ofs << "             .X%SSS%X%SSSSX%SSSSSSSSSSS%SS%SS%SSX8t%SX%SS; " << std::endl;
		ofs << "            .  . :. .  ..   .  .   .  .  . . . .;;: .  .  . " << std::endl;
		ofs << "            %%X%@8X%SS%X%SS%SS%%S%SS%SS%SS%SS%SS%SS%SS%SS%S " << std::endl;
		ofs << "         t%S%%%%tS%%X%%S%%S%%St%Xt%S%%St%S%%%%%%%%%%%StS%tS%%% " << std::endl;
		ofs << "         ::::::::::::::::::::::::::::::::::::::::::::::::::::: " << std::endl;
		ofs << "                .;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;. " << std::endl;
		ofs << "               ..........................:...........:.. " << std::endl;
		ofs << "               ;t%tt%tt%tS8%t%tt%t%%t%%88%;%%tt%t%ttt%tt " << std::endl;
		ofs << "              ::::::::::::S%;;:::.::.:;%tt::::::.:::::.::. " << std::endl;
		ofs << "             .;;:;:;;:;;:tt;;;;:;;;;;;;;t;:;;:;;;;;:;;;;;. " << std::endl;
		ofs << "            tt%%tS%t%%tSt%St%%t%S;tSt%%%t%%%%%%%t%%t%%t%%t% " << std::endl;
		ofs << "            ::;::;::;::;::;::;X8t;:;:;:::;::;::;:;::;::; " << std::endl;
		ofs << "          .XS%XS%X%SX%SSS%X%SSSS%SSSS%SS%SS8:S%SS%%tSSX%SS%XS; " << std::endl;
		ofs << "         . . . . :. .  . .  ..  .::... . .. . .;. .. . . . . " << std::endl;
		ofs << "         %%SS%S%8.8%SS%S%SS%%S%SS%SS%SS%SS%SS%SS%SS%SS88S%SS%SS%S " << std::endl;
		ofs << "      t%S%%%%tS%%X%%S%%S%%St%Xt%S%%St%S%%%%%%%%%%%StS%t%StS%tS%%S " << std::endl;
		ofs << "         .::....           . .   ;SX@S:               .." << std::endl;
		ofs << "                                 S8888; " << std::endl;
		ofs << "                                .%8888t " << std::endl;
		ofs << "                                .tS8@S; " << std::endl;
		ofs << "                                .X88 8: " << std::endl;
		ofs << "                           .;;;;t%X%t%%;t:t;. " << std::endl;
		ofs << "                           %888888@88888@8@8: " << std::endl;
		ofs << "                          .%8888888@8888@8@8; " << std::endl;
		ofs << "                          .%88@8X8@888@888@8; " << std::endl;
		ofs << "                          .;:t:;;;;;;;;;;;:; " << std::endl;
		ofs << "" << std::endl;
		ofs << "		 __    __ " << std::endl;
		ofs << "		/  |  /  | " << std::endl;
		ofs << "		$$ |  $$ |  ______    ______    ______   __    __ " << std::endl;
		ofs << "		$$ |__$$ | /      \\  /      \\  /      \\ /  |  /  |" << std::endl;
		ofs << "		$$    $$ | $$$$$$  |/$$$$$$  |/$$$$$$  |$$ |  $$ | " << std::endl;
		ofs << "		$$$$$$$$ | /    $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ | " << std::endl;
		ofs << "		$$ |  $$ |/$$$$$$$ |$$ |__$$ |$$ |__$$ |$$ \\__$$ | " << std::endl;
		ofs << "		$$ |  $$ |$$    $$ |$$    $$/ $$    $$/ $$    $$ | " << std::endl;
		ofs << "		$$/   $$/  $$$$$$$/ $$$$$$$/  $$$$$$$/   $$$$$$$ | " << std::endl;
		ofs << "		                    $$ |      $$ |      /  \\__$$ | " << std::endl;
		ofs << "		                    $$ |      $$ |      $$    $$/ " << std::endl;
		ofs << "		                    $$/       $$/        $$$$$$/ " << std::endl;
		ofs << "		 __    __ " << std::endl;
		ofs << "		/  \\  /  | " << std::endl;
		ofs << "		$$  \\ $$ |  ______   __   __   __ " << std::endl;
		ofs << "		$$$  \\$$ | /      \\ /  | /  | /  | " << std::endl;
		ofs << "		$$$$  $$ |/$$$$$$  |$$ | $$ | $$ | " << std::endl;
		ofs << "		$$ $$ $$ |$$    $$ |$$ | $$ | $$ | " << std::endl;
		ofs << "		$$ |$$$$ |$$$$$$$$/ $$ \\_$$ \\_$$ | " << std::endl;
		ofs << "		$$ | $$$ |$$       |$$   $$   $$/ " << std::endl;
		ofs << "		$$/   $$/  $$$$$$$/  $$$$$/$$$$/ " << std::endl;
		ofs << "" << std::endl;
		ofs << "		 __      __ " << std::endl;
	    ofs << "		/  \\    /  | " << std::endl;             
	    ofs << "		$$  \\  /$$/______    ______    ______ " << std::endl;
		ofs << "		 $$  \\/$$//      \\  /      \\  /      \\ " << std::endl;
		ofs << "		  $$  $$//$$$$$$  | $$$$$$  |/$$$$$$  | " << std::endl;
		ofs << "		   $$$$/ $$    $$ | /    $$ |$$ |  $$/ " << std::endl;
		ofs << "		    $$ | $$$$$$$$/ /$$$$$$$ |$$ | " << std::endl;
		ofs << "		    $$ | $$       |$$    $$ |$$ | " << std::endl;
		ofs << "		    $$/   $$$$$$$/  $$$$$$$/ $$/ " << std::endl;   
		ofs << "" << std::endl;
		ofs << "" << std::endl;
	ofs.close();
	}
	else {
		std::cout << RED << "\t< ShrubberyCreationForm >" << RESET;
		std::cout << " could not open file: [" << this->_target << "_shrubbery]" << std::endl;
	}

	return ;
}
