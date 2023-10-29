/*
** This is an implementation of a Weapon class.
** It has a `private` string attribute `type`.
** `getType` member function that returns a const reference 
** to the `type` attribute of the Weapon instance.
** `setType` member function that sets the `type` using the 
** new one passed as argument. 
*/

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>
# include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string &getType(void);
		void setType(std::string type);
};

#endif
