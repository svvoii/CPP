#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondTrap);
		~DiamondTrap(void);

		DiamondTrap &operator=(const DiamondTrap &diamondTrap);

		void attack(std::string const &target);
		void whoAmI(void);

};

#endif
