#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include "Weapon.class.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);

		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif
