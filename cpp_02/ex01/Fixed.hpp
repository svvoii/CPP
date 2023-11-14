/*
** In this exercise we will extend the previous exercise by adding
** the following member functions:
** A constructor that takes a constant integer as a parameter and
** converts it to the corresponding fixed point value.
**
** A constructor that takes a constant floating point number as a
** parameter and converts it to the corresponding fixed point value.
**
** A member function `float toFloat(void) const` that converts the
** fixed point value to a floating point value.
**
** A member function `int toInt(void) const` that converts the 
** fixed point value to an integer value.
**
** An overload of the output operator `<<` that inserts a floating 
** point representation of the fixed point value into the
** output stream passed as parameter.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed(void);

		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

/*
** The following declaration is used to overload the `std::ostream`
** operator `<<` so that it can be used with the `Fixed` class.
** This operator inserts a FLOATING point representation of the
** fixed point value into the output stream passed as parameter.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
