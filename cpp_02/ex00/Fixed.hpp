/*
** This is the example of the class in Orthodox Canonical Form.
** And it represents a fixed point number.
**
** The private members are:
** `int _rawBits` - the raw value of the fixed point number.
** `static const int _fractionalBits` - the number of fractional bits,
** which always be the integer literal 8.
**
** The public members are:
** `Fixed(void)` - the default constructor.
** `Fixed(const Fixed &fixed)` - the copy constructor.
** `Fixed &operator=(const Fixed &fixed)` - the assignation operator overload.
** `~Fixed(void)` - the destructor.
** `int getRawBits(void) const` - returns the raw value of the fixed point number.
** `void setRawBits(int const raw)` - sets the raw value of the fixed point number.
**
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		~Fixed(void);

		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
