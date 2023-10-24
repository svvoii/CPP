/*
** My Awesome PhoneBook program.
**
** User input shall be handled accordingly:
**
** `ADD` : save a new contact in the `PhoneBook`. 
** command should prompt the user to input the contact information,
** one field at a time and store it in the `PhoneBook` as a new `Contact`.
**
** `SEARCH` : display a specific contact.
** Should display the saved contact as a list of 4 columns: 
** `index`, `first name`, `last name`, `nickname`.
** Each column should have a width of 10 characters, separated by a `|` character.
** If the value is longer, it should be truncated and
** if the last character is truncated, it should be replaced with a dot.
** The user should then be prompted to enter the index of the contact to display.
** If the index does not exist, the program should display an error message.
** Otherwise, the program should display the contact information one field per line.
**
** `EXIT` : exit the program.
**
** The program should loop until the `EXIT` command is given.
*/

#include "PhoneBook.class.hpp"

int main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << std::endl;
		std::cout << "'ADD' to add a contact." << std::endl;
		std::cout << "'SEARCH' to search for a contact." << std::endl;
		std::cout << "'EXIT' to exit the phone book." << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	PhoneBook	phoneBook;

	std::cout << "Welcome to your Awesome phone book!" << std::endl;
	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			phoneBook.addContact();
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else if (input == "EXIT") {
			phoneBook.exitPhoneBook();
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}
