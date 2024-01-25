// Adding Some color to the output
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
/*
** This exccercise is about serialization of data.
**
** The main function tests the serialization of a `Data` struct.
** First we create a `Data` struct with random values.
** Then we use `serialize` on the address of the Data object.
** Then we pass the result of `serialize` to `deserialize`
** and check if the result is the same as the original `Data` object.
*/

#include "Serializer.hpp"

int main() {

	srand(time(NULL));
	
	Data	*data = new Data;

	data->s1 = Serializer::_randomString();
	data->n = Serializer::_randomInt();
	data->s2 = Serializer::_randomString();
	
	std::cout << std::endl;
	std::cout << MAGENTA << "Raw data in the 'Data' struct @: " << RESET << data << std::endl;	
	//std::cout << "Data:" << std::endl;
	std::cout << CYAN << "\ts1: [" << data->s1 << "]" << RESET << std::endl;
	std::cout << CYAN << "\tn : [" << data->n << "]" << RESET << std::endl;
	std::cout << CYAN << "\ts2: [" << data->s2 << "]" RESET << std::endl;
	std::cout << std::endl;
	
	// uintptr_t	serializedData = Serializer::serialize(data);
	unsigned long	serializedData = Serializer::serialize(data);
	
	std::cout << GREEN << "Applying 'Serialized data' method." << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "serializedData value (unsigned long): " << RESET << "[" << serializedData << "]" << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "Applying 'Deserialize(serializedData)' method." << RESET << std::endl;
	Data	*deserializedData = Serializer::deserialize(serializedData);
	std::cout << std::endl;
	
	std::cout << MAGENTA << "Data @ deserializedData pointer: " << RESET << deserializedData << std::endl;
	std::cout << CYAN << "\ts1: [" << deserializedData->s1 << "]" << RESET << std::endl;
	std::cout << CYAN << "\tn : [" << deserializedData->n << "]" << RESET << std::endl;
	std::cout << CYAN << "\ts2: [" << deserializedData->s2 << "]" RESET << std::endl;
	std::cout << std::endl;
	
	delete data;
	return 0;
}
