#ifndef CLASSES_H
# define CLASSES_H

/*
** Bellow is the implementation of two classes:
** `PhoneBook` and `Contact`.
**
** The `PhoneBook` class is a container for `Contact` objects.
** The `Contact` class is a container for contact information.
** 
** Basic requirenments:
** The `Contact` class should have arbitrary fields:
** `first name`, `last name`, `nickname`, `phone number`, `darkest secret`.
** A saved contact should not have empty fields.
** Attributes and methods should be designed using both
** `public` and `private` access specifiers.
**
** `PhoneBook` should have an array `contacts` of `Contact` objects,
** of max size `8` (eight) contacts.
** If there is a new contact to add (above the max size), 
** the program should replace the oldest one with the new one.
** The values shall be stored on the stack.
**
** The `PhoneBook` class should have three mandatory methods:
** `add`, `search`, `exit`.
** These methods should be used in the main program to store
** and search for contacts given by the user as input.
**
*/

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cctype>

# define MAX_CONTACTS 8

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_underwearColor;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

	void	setContact(void);
	void	displayContactShort(void) const;
	void	displayContactFull(void) const;

};

class PhoneBook {
private:
	Contact		_contacts[MAX_CONTACTS];
	int			_contactCount;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	displayContacts(void) const;
	void	searchContact(void);
	void	exitPhoneBook();

};

#endif
