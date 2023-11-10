#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class ICharacter;

/*
** This is an Abstract class, which is used as a base in `Cure` and `Ice` classes.
** The methods `clone` and `use` are should be implemented in the derived classes.
** In this example, its `Cure` and `Ice` classes.
*/
class AMateria {
	protected:
		std::string		_type;
		unsigned int	_xp;
	
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);
		
		AMateria &	operator=(AMateria const & rhs);
		
		std::string const &	getType(void) const;
		unsigned int		getXP(void) const;
		
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter & target);
};

/*
** This is an Interface class, which is used as a base in `Character` class.
** It is pure virtual, and not implemented separately.
*/
class ICharacter {
	public:
		virtual ~ICharacter(void) {}
		
		virtual std::string const &	getName(void) const = 0;
		
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter & target) = 0;
};

/*
** This is an Interface class, which is used as a base in `MateriaSource` class.
** It is pure virtual, and not implemented separately.
*/
class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {}
		
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
