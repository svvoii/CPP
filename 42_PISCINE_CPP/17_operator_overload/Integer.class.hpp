#ifndef INTEGER_CLASS_HPP
# define INTEGER_CLASS_HPP

# include <iostream>

class Integer {

	public:

		Integer(int const n);
		~Integer(void);

		int		getValue(void) const;

		Integer&	operator=(Integer const &rhs);
		Integer		operator+(Integer const &rhs) const;

	private:

		int		_nbr;

};

std::ostream&	operator<<(std::ostream& o, Integer const & rhs);

#endif // INTEGER_CLASS_HPP
