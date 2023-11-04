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
		
		static std::string const	_randomString();
		static int const			_randomInt();
		
	public:
		Serializer();
		Serializer(Serializer const &other);
		~Serializer();
		Serializer &operator=(Serializer const &other);
		
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
