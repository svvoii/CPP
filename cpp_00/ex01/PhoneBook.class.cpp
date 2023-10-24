#include "PhoneBook.class.hpp"

/* ********************************************************* */
/* PHONEBOOK CLASS INITIALIZATION 							*/
/* ********************************************************* */

PhoneBook::PhoneBook(void) {
	this->_contactCount = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void PhoneBook::addContact(void) {
	if (this->_contactCount < MAX_CONTACTS) {
		this->_contacts[this->_contactCount].setContact();
		this->_contactCount++;
	} else {
		std::cout << "Phone book is full." << std::endl;
	}
	return;
}

void PhoneBook::displayContacts(void) const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		this->_contacts[i].displayContactShort();
	}
	return;
}

void	PhoneBook::searchContact(void) {
	std::string	input;
	int			index;

	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index < this->_contactCount) {
			this->_contacts[index].displayContactFull();
		} else {
			std::cout << "Invalid index." << std::endl;
		}
	} else {
		std::cout << "Invalid index." << std::endl;
	}
	return;
}

void PhoneBook::exitPhoneBook(void) {
	std::cout << "Exiting phone book." << std::endl;
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
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->_firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	std::cout << "Enter underwear color: ";
	std::getline(std::cin, this->_underwearColor);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->_darkestSecret);
	return;
}

void Contact::displayContactShort(void) const {
	std::cout << std::setw(10) << this->_firstName.substr(0, 10) << "|";
	std::cout << std::setw(10) << this->_lastName.substr(0, 10) << "|";
	std::cout << std::setw(10) << this->_nickname.substr(0, 10) << std::endl;
	return;
}

void Contact::displayContactFull(void) const {
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Underwear color: " << this->_underwearColor << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	return;
}
