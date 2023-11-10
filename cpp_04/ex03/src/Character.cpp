/*
** Implementation of Character class, which inherits from ICharacter.
*/

#include "../includes/Character.hpp"

/*
** Constructors
*/
Character::Character(void) :
	_name("default"),
	_inventorySize(0) {

	std::cout << CYAN << "\t< Character default constructor called > " << RESET;
	std::cout << "name: [" << this->_name << "],\tinventory size: [" << this->_inventorySize << "]" << std::endl;
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : 
	_name(name),
	_inventorySize(0) {

	std::cout << CYAN << "\t< Character parametric constructor called > " << RESET;
	std::cout << "name: [" << this->getName() << "],\tinventory size: [" << this->getInventorySize() << "]" << std::endl;
	//std::cout << "Character parametric constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const & src) {

	std::cout << CYAN << "\t< Character copy constructor called > " << RESET;
	std::cout << "name: [" << src._name << "],\tinventory size: [" << src._inventorySize << "]" << std::endl;
	//std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

/*
** Destructor
*/
Character::~Character(void) {

	std::cout << RED << "\t< Character destructor called > " << RESET;
	std::cout << "name: [" << this->_name << "],\tinventory size: [" << this->_inventorySize << "]" << std::endl;
	//std::cout << "Character destructor called" << std::endl;
	this->_deleteInventory();
}

/*
** Operators overload
*/
Character &	Character::operator=(Character const & rhs) {

	std::cout << CYAN << "\t< Character assignment operator called > " << RESET;
	std::cout << "name: [" << this->_name << "],\tinventory size: [" << this->_inventorySize << "]" << std::endl;
	//std::cout << "Character assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_deleteInventory();
		this->_copyInventory(rhs);
	}
	return (*this);
}

/*
** Public member functions
*/
std::string const &	Character::getName(void) const {

	return (this->_name);
}

// Testing purposes
int		Character::getInventorySize(void) const {

	return (this->_inventorySize);
}

void	Character::printInventory(void) {

	std::cout << "[" << this->_name << "] has [" << this->_inventorySize << "] materia(s) in his inventory:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL) {
			std::cout << "\t" << i + 1 << " [ " << this->_inventory[i]->getType() << " ]" << std::endl;
		}
	}
}

/*
** This method will check if the inventory is full, and if not, will add the materia
** to the first empty slot in the inventory.
** By adding a materia to the inventory, we basically just assign the address of the
** materia to the pointer in the inventory.
**
** In the same way the `unequip` method will just reset the pointer to NULL, without
** deleting the materia.
*/
void	Character::equip(AMateria* m) {

	if (this->_inventorySize < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				this->_inventorySize++;
				break ;
			}
		}
	}
	else {
		std::cout << "Inventory is full" << std::endl;
	}
}

/*
** This method will just reset the pointer to NULL, but will not delete the materia,
** which was created separately and equipped to the inventory.
*/
void	Character::unequip(int idx) {

	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
		this->_inventorySize--;
	}
	else  {
		std::cout << "Invalid index: [" << idx << "]" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {

	std::cout << "[" << this->_name << "] uses materia at index [" << idx << "]" << std::endl;
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
	else {
		std::cout << "Invalid index: [" << idx << "]" << std::endl;
	}
}

/*
** Private member functions
void	Character::_deleteInventory(void) {

	int i = 0;

	if (this->_inventorySize > 0) {
		while (this->_inventorySize > 0)
		{
			i = this->_inventorySize - 1;
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			this->_inventorySize--;
		}
	}
}
*/
void	Character::_deleteInventory(void) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

void	Character::_copyInventory(Character const & src) {

	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

/*
** Non-member functions
std::ostream &	operator<<(std::ostream & o, Character const & rhs) {

	o << rhs.getName() << " has " << rhs._inventorySize << " materia(s) in his inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i] != NULL)
			o << " - " << rhs._inventory[i]->getType() << std::endl;
	}
	return (o);
}
*/
