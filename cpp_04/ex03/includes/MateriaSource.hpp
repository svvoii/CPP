#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

// class AMateria;

/*
** This is an Interface class, which is used as a base in `MateriaSource` class.
** It is pure virtual, and not implemented separately.
class IMateriaSource {
	public:
		virtual ~IMateriaSource(void) {}
		
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};
*/

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_materia[4];

		void		_deleteMateria(void);
		void		_copyMateria(MateriaSource const & src);

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource(void);
		
		MateriaSource &	operator=(MateriaSource const & rhs);

		// Testing purposes
		int				getInventorySize(void) const;
		void			printMateria(void);
		
		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
