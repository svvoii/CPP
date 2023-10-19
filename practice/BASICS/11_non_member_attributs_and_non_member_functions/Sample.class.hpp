/*
** In this Class we add a static int _nbInst
** to illustrate the use of non-member attributes.
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	Sample(void);
	~Sample(void);

	static int	getNbInst(void);

private:

	static int	_nbInst;

};

#endif

/*
** `static` is a keyword that can be used to declare a non-member attribute.
** Non-member attributes are attributes that are not part of the class.
** They are not part of the class, but they are still part of the program.
**
** See the Sample.class.cpp file for more details.
*/