/*
** Here we implement the Serializer class
** `static class Serializer` with the following methods:
**
** `uintptr_t serialize(Data *ptr)` it will return the 
** address of the Data object as a uintptr_t.
**
** `Data *deserialize(uintptr_t raw)` it will return a pointer
** to a Data object, the pointer is created from the raw address.
*/

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>
// # include <cstdint>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

class Serializer {
	private:
		static std::string const	_alphabet;
		static std::string const	_digits;
		static std::string const	_special;
		
	public:
		Serializer();
		Serializer(Serializer const &other);
		~Serializer();
		Serializer &operator=(Serializer const &other);

		static std::string const	_randomString();
		static int					_randomInt();
		
		// static uintptr_t serialize(Data *ptr);
		// static Data *deserialize(uintptr_t raw);
		static unsigned long	serialize(Data *ptr);
		static Data	*deserialize(unsigned long raw);
};

#endif

/* 
** `uintptr_t` is an unsigned integer type that is capable of storing a data pointer.
** However, `uintptr_t` is not present in the -std=c++98 standard library !!
** There is an error in the subject of this exercise !!!
**
** To use `uintptr_t` you must include the <cstdint> header and compile with the -std=c++11.
** Otherwise `unsigned long` type shall be used.
*/
