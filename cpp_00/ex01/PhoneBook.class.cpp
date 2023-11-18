# include "PhoneBook.class.hpp"

#define HORISONTAL_LINE "───────────────────────────────────────────"

/* ********************************************************* */
/* PHONEBOOK CLASS INITIALIZATION 							*/
/* ********************************************************* */

PhoneBook::PhoneBook(void) {
	this->_contactCount = 0;
	this->_isFull = false;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void PhoneBook::displayPrompt(void) const {

	std::cout << MAGENTA << std::endl;
	//std::cout << "Welcome to your Awesome phone book!" << std::endl;
	std::cout << "Enter command: < ADD >, < SEARCH > or < EXIT >" << RESET << std::endl;
	std::cout << "\nCommand: ";

	return;
}

/*
** The following function is used to convert the input string to lowercase
** and trim the whitespace from the beginning and end of the string.
**
** `input.erase(0, input.find_first_not_of(" \n\r\t"));` - erases the whitespace
** from the beginning of the string. `0` is the starting position.
**
** `input.erase(input.find_last_not_of(" \n\r\t") + 1);` - erases the whitespace
** beginning from the end of the string.
*/
void PhoneBook::inputToLowerAndTrim(std::string &input) {

	for (size_t i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	input.erase(0, input.find_first_not_of(" \n\r\t"));
	input.erase(input.find_last_not_of(" \n\r\t") + 1);

	return;
}

void PhoneBook::addContact(void) {

	if (this->_contactCount == MAX_CONTACTS) {
		std::cout << "Phone book is full. ";
		std::cout << "Overwriting the oldest contact." << std::endl;
		this->_contactCount = 0;
		this->_isFull = true;
	}
	this->_contacts[this->_contactCount].setContact();
	this->_contactCount++;
}

void PhoneBook::displayContacts(void) const {

	std::cout << CYAN << HORISONTAL_LINE << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; (i < this->_contactCount) || (this->_isFull && i < MAX_CONTACTS); i++) {
		
		std::cout << HORISONTAL_LINE << std::endl;
		std::cout << std::setw(10) << i << "|";
		this->_contacts[i].displayContactShort();
	}

	std::cout << HORISONTAL_LINE << RESET << std::endl;
}

void	PhoneBook::searchContact(void) {

	std::string	input;
	int			index;

	if (this->_contactCount == 0) {
		std::cout << std::endl;
		std::cout << CYAN << "Phone book is empty." << RESET << std::endl;

		return;
	}

	this->displayContacts();

	std::cout << "Enter index: ";

	if (!std::getline(std::cin, input)) {
		return;
	}

	if (input.length() == 1 && isdigit(input[0])) {

		index = input[0] - '0';
		if ((index >= 0 && index < _contactCount) || (index >= 0 && _isFull && index < MAX_CONTACTS)) {
			this->_contacts[index].displayContactFull();
		}
		else {
			std::cout << "Invalid index." << std::endl;
		}
	}
	else {
		std::cout << "Invalid index." << std::endl;
	}
	return;
}

void PhoneBook::exitPhoneBook(void) {

	std::cout << RED << "Exiting phone book. Goodbye!" << RESET << std::endl;
	std::cout << std::endl;
	return;
}

/* ********************************************************* */
/* CONTACT CLASS INITIALIZATION 							*/
/* ********************************************************* */

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

void Contact::setContact(void) {

	std::string fields[6] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"underwear color",
		"darkest secret"
	};
	std::string values[6];
	std::string input;

	for (int i = 0; i < 6; i++) {
		std::cout << "Enter " << fields[i] << ": ";
		
		if (!std::getline(std::cin, input)) {
			//std::cout << "Input interrupted." << std::endl;
			return;
		}
		else if (input.empty()) {
			std::cout << "..input cannot be empty. Try again." << std::endl;
			i--;
		}

		if (fields[i] == "phone number") {
			for (size_t j = 0; j < input.length(); j++) {
				if (!isdigit(input[j])) {
					std::cout << "..phone number must be numeric. Try again." << std::endl;
					i--;
					break;
				}
			}
		}

		values[i] = input;
	}

	this->_firstName = values[0];
	this->_lastName = values[1];
	this->_nickname = values[2];
	this->_phoneNumber = values[3];
	this->_underwearColor = values[4];
	this->_darkestSecret = values[5];

	return;
}

void Contact::displayContactShort(void) const {

	std::cout << std::setw(10) << this->_firstName.substr(0, 10) << "|";
	std::cout << std::setw(10) << this->_lastName.substr(0, 10) << "|";
	std::cout << std::setw(10) << this->_nickname.substr(0, 10) << std::endl;

	return;
}

void Contact::displayContactFull(void) const {

	std::cout << std::endl << "Here is your data:" << std::endl;
	std::cout << CYAN;
	std::cout << "First name:   \t" << this->_firstName << std::endl;
	std::cout << "Last name:    \t" << this->_lastName << std::endl;
	std::cout << "Nickname:     \t" << this->_nickname << std::endl;
	std::cout << "Phone number:  \t" << this->_phoneNumber << std::endl;
	std::cout << "Underwear col:\t" << this->_underwearColor << std::endl;
	std::cout << "Darkest secret:\t" << this->_darkestSecret << std::endl;
	std::cout << RESET;

	return;
}
