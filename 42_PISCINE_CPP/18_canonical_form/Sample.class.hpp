/*
** This class demonstrates the
** concept of canonical form class in C++.
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

# include <iostream>

// example of a canonical form class:
class Sample {

public:

	Sample(void);								// canonical/standard form constructor
	Sample(int const n);
	Sample(Sample const & src);					// canonical/standard form copy constructor
	~Sample(void);								// canonical/standard form destructor

	Sample & operator=(Sample const & rhs);		// canonical/standard form assignment operator overload

	int		getVariable(void) const;

private:

	int		_variable;

};

std::ostream & operator<<(std::ostream & o, Sample const & rhs);	// not part of the canonical form

#endif

/*
** `.. & operator<<(..)` is not part of the canonical form.
** However, it is a good practice to implement it since it
** allows you to use the `<<` operator on your class.
**
** See the Sample.class.cpp and main.cpp file for usage details.
*/