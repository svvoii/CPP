/*
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	int		publicVariable;

	Sample(void);
	~Sample(void);

	void	publicFunction(void) const;

private:

	int		_privateVariable;
	void	_privateFunction(void) const;

};

#endif

/*
** This example shows the concept of encapsulation.
** `private` members are only accessible from within the class.
** `public` members are accessible from anywhere.
*/