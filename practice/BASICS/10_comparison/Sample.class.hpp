/*
** In this Class we add a Sample *other 
** to the setPrivateVariable method.
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	Sample(int value);
	~Sample(void);

	int		getPrivateVariable(void) const;
	int		comparison(Sample *other) const;

private:

	int		_privateVariable;

};

#endif

/*
** `(Sample *other)` is a pointer to a Sample object.
** This will be used to demonstrate the use of 
** comparison between two objects.
**
** See the Sample.class.cpp file for more details.
*/