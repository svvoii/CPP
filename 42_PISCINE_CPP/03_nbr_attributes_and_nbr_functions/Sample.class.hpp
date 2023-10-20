/*
** This program demonstrates the use of 
** number attributes and
** number functions.
**
** see also Sample.class.cpp where the 
** definition of the class's attributes,
** functions / methods are defined.
**
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	int		variable; // attribute

	Sample(void); // constructor
	~Sample();	  // destructor

	void	function(void); // method

};

#endif

/*
** Here in the Class declaration we declare 
** its attributes, as well its 
** methods/functions in the same way.
** 
** The definition of the attributes and
** methods/functions are handled in the `.class.cpp` file.
*/