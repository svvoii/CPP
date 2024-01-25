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

std::string const Serializer::_alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string const Serializer::_digits = "0123456789";
//std::string const Serializer::_special = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

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
	int			randomLength = rand() % 50 + 1;
	
	for (int i = 0; i < randomLength; i++) {
		randomString += _alphabet[rand() % _alphabet.length()];
	}
	return randomString;
}

int Serializer::_randomInt() {

	return rand() % 1000;
}

unsigned long Serializer::serialize(Data *ptr) {

	unsigned long	serializedData;
	
	serializedData = reinterpret_cast<unsigned long>(ptr);
	return serializedData;
}

Data *Serializer::deserialize(unsigned long raw) {

	Data	*deserializedData;
	
	deserializedData = reinterpret_cast<Data *>(raw);
	return deserializedData;
}

// uintptr_t Serializer::serialize(Data *ptr) {

// 	uintptr_t	serializedData;
	
// 	serializedData = reinterpret_cast<uintptr_t>(ptr);
// 	return serializedData;
// }

// Data *Serializer::deserialize(uintptr_t raw) {

// 	Data	*deserializedData;
	
// 	deserializedData = reinterpret_cast<Data *>(raw);
// 	return deserializedData;
// }

/*
** `reinterpret_cast` is a type of casting operator that
** converts any pointer type to any other pointer type.
** In this case, we are converting a pointer to Data object
** to an unsigned long and vice versa.
** This is a form of serialization and deserialization.
**
** Serialization is the process of converting an object into
** a stream of bytes to store the object or transmit it to memory,
** a database, or a file. Its main purpose is to save the state of
** an object in order to be able to recreate it when needed.
*/