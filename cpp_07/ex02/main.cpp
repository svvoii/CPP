#include "Array.hpp"
#include <iostream>

int main()
{
	// Trying out the default constructor, access operator and size method.
	std::cout << MAGENTA << "= = = = = = = = = = TEST 1 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Trying out the default constructor, access operator and size method." << RESET << std::endl;
	std::cout << "Declaring a new Array: `Array<int> intArray(5);`" << std::endl;
	Array<int> intArray(5);

	std::cout << "Printing an empty array: " << std::endl;
	std::cout << "intArray.size() = [" << intArray.size() << "]" << std::endl;
	// Printing out the values in an empty array
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Setting some values with a loop: `intArray[i] = i;`..." << std::endl;
	// Setting some values in the array
	for (size_t i = 0; i < intArray.size(); i++) {
		intArray[i] = i;
	}
	std::cout << std::endl;

	std::cout << "Printing the array with values: " << std::endl;
	// Printing out the values in the array
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Copy constructor in action !
	std::cout << MAGENTA << "= = = = = = = = = = TEST 2 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Copy constructor in action !" << RESET << std::endl;
	std::cout << "Declaring a new Array as a copy of the previous one: `Array<int> intArrayCopy(intArray);`" << std::endl;
	
	Array<int> intArrayCopy(intArray);

	std::cout << "intArrayCopy.size() = [" << intArrayCopy.size() << "]" << std::endl;
	std::cout << "Printing the copied Array: " << std::endl;
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Printing the original `intArray`: " << std::endl;
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Playing with the assignment operator.
	std::cout << MAGENTA << "= = = = = = = = = = TEST 3 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Playing with the assignment operator." << RESET << std::endl;
	std::cout << "Declaring a new Array as `Array<int> intArr2;` and then assigning it to `intArr2 = intArray;`" << std::endl;
	Array<int> intArr2;
	intArr2 = intArray;

	std::cout << "intArr2.size() = [" << intArr2.size() << "]" << std::endl;
	std::cout << "Printing the `intArr2`: " << std::endl;
	for (size_t i = 0; i < intArr2.size(); i++) {
		std::cout << intArr2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Checking if the `intArray` is still there: " << std::endl;
	std::cout << "intArray.size() = [" << intArray.size() << "]" << std::endl;
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Testing the destructor.
	std::cout << MAGENTA << "= = = = = = = = = = TEST 4 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Destruction !" << RESET << std::endl;
	std::cout << "Creating a new Array with `Array<int> *arr = new Array<int>(5);`" << std::endl;
	Array<int> *arr = new Array<int>(5);
	
	std::cout << "Using `delete arr;`" << std::endl;
	std::cout << std::endl;
	delete arr;

	// Testing an array of strings.
	std::cout << MAGENTA << "= = = = = = = = = = TEST 5 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Testing an array of strings." << RESET << std::endl;
	std::cout << "Declaring a new Array: `Array<std::string> stringArray(3);`" << std::endl;
	std::cout << "Setting some values as: `stringArray[0] = \"Hello\";`..." << std::endl; 
	std::cout << "Output: " << std::endl;
	// Create an array of strings with size 3
	Array<std::string> stringArray(3);

	// Setting some values in the array
	stringArray[0] = "Wake";
	stringArray[1] = "up";
	stringArray[2] = "Neo";

	// Printing out the values in the array
	for (size_t i = 0; i < stringArray.size(); i++) {
		std::cout << stringArray[i] << std::endl;
	}
	std::cout << std::endl;

	// Accessing with an index out-of-bounds
	std::cout << MAGENTA << "= = = = = = = = = = TEST 6 = = = = = = = = = = =" << RESET << std::endl;
	std::cout << BLUE << "Accessing an out-of-bounds index as: `intArray[10] = 42;`" << RESET << std::endl;
	std::cout << "intArray.size() = [" << intArray.size() << "]" << std::endl;
	std::cout << std::endl;
	try {
		intArray[10] = 42;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << MAGENTA << "= = = = = = = = = = THE END = = = = = = = = = = =" << RESET << std::endl;

	return 0;
}
