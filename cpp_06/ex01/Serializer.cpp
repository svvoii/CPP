/*
** Here is the definition of the Serializer class
** `static class Serializer` with the following methods:
**
** `uintptr_t serialize(Data *ptr)` it will return the
** address of the Data object as a uintptr_t.
**
** `Data *deserialize(uintptr_t raw)` it will return a pointer
** to a Data object, the pointer is created from the raw address.
*/

#include "Serializer.hpp"

std::string const	Serializer::_alphabet = "abcdefghijklmnopqrstuvwxyz";
std::string const	Serializer::_digits = "0123456789";
std::string const	Serializer::_special = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

Serializer::Serializer() {
}

Serializer::Serializer(Serializer const &other) {
	*this = other;
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=(Serializer const &other) {
	if (this != &other) {
	}
	return *this;
}

std::string const	Serializer::_randomString() {
	std::string	randomString;
	int			randomLength = rand() % 10 + 1;
	
	for (int i = 0; i < randomLength; i++) {
		randomString += _alphabet[rand() % _alphabet.length()];
	}
	return randomString;
}

int const			Serializer::_randomInt() {
	return rand() % 1000;
}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t	serializedData;
	
	serializedData = reinterpret_cast<uintptr_t>(ptr);
	return serializedData;
}

Data *Serializer::deserialize(uintptr_t raw) {
	Data	*deserializedData;
	
	deserializedData = reinterpret_cast<Data *>(raw);
	return deserializedData;
}
