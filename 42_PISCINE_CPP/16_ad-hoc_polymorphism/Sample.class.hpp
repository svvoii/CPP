/*
** This class is used to demonstrate the 
** concept of ad-hoc polymorphism.
**
** It is the ability to use the same 
** function name with different parameters.
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	Sample(void);
	~Sample(void);

	void	function(char const c) const;
	void	function(int const nbr) const;
	void	function(float const fl) const;
	void	function(Sample const & i) const;

};

#endif

/*
** See the Sample.class.cpp and main.cpp file for usage details.
*/