/*
**
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	float const	pi;	// const member attribute
	int			variable;

	Sample(float const fl);
	~Sample();

	void	function(void) const; // const member function

};

#endif

/*
** 
*/