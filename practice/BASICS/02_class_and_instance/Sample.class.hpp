/*
** This header file contains the declaration 
** of the basic class in c++
**
** see Sample.class.cpp
** which demonstrates the use of classes and instances.
**
** About the naming convention:
** Sample.class.hpp
** .class.hpp is used to indicate that 
** this is a header file where the given
** class is declared.
**
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	Sample(void); // constructor
	~Sample();	  // destructor
};

#endif

/*
** When initailizing a class in .cpp file:
** Once the Class is instantiated, the constructor is called.
** Once the Class is destroyed, the destructor is called.
**
** Constructor and destructor do not have any return type.
**
*/