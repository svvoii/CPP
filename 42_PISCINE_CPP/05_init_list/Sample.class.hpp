/*
**
*/

#ifndef _SAMPLE1_CLASS_HPP_
# define _SAMPLE1_CLASS_HPP_

class Sample1 {

public:

	// attributes
	char	c_var;
	int		num_var;
	float	fl_var;

	Sample1(char c_var, int num_var, float fl_var); // constructor
	~Sample1(void);	  // destructor

};

class Sample2 {

public:

	// attributes
	char	c_var;
	int		num_var;
	float	fl_var;

	Sample2(char c_var, int num_var, float fl_var); // constructor
	~Sample2(void);	  // destructor

};

#endif

/*
** In this example of class Sample declaration
** we use the constructor to initialize 
** this class's attributes via the initializer list.
*/