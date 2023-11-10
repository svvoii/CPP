#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

//class AMateria;

/*
** This is an Interface class, which is used as a base in `Character` class.
** It is pure virtual, and not implemented separately.
class ICharacter {
	public:
		virtual ~ICharacter(void) {}
		
		virtual std::string const &	getName(void) const = 0;
		
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter & target) = 0;
};
*/

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria*	_inventory[4]; // 4 is the max size of the inventory for a character
		int			_inventorySize;
		
		void		_deleteInventory(void);
		void		_copyInventory(Character const & src);
	
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character(void);
		
		Character &	operator=(Character const & rhs);
		
		virtual std::string const &	getName(void) const;
		// Testing purposes
		int							getInventorySize(void) const;
		void						printInventory(void);
		
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

//std::ostream &	operator<<(std::ostream & o, Character const & rhs);

#endif
