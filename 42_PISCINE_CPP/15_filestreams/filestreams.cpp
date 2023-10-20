#include <iostream>
#include <fstream>

int main() {
	/* Example of reading from the file into int variables */

	std::ifstream ifsNumbers("numbers.txt");
	unsigned int	num1;
	unsigned int	num2;

	ifsNumbers >> num1 >> num2;

	std::cout << "num1: " << num1 << std::endl; 
	std::cout << "num2: " << num2 << std::endl; 
	std::cout << std::endl;

	/* ****************************************************************** */

	/* Create an output file stream object and open a file for writing */

	std::ofstream outfile("example.txt");
	
	outfile << "Wake up Neo.." << std::endl; // Write some data to the file
	outfile << "The Matrix has you.." << std::endl;
	outfile << "Follow the white rabbit." << std::endl;
	outfile << "Knock, knock, Neo." << std::endl;

	outfile.close();

	/* ****************************************************************** */

	/* Create an input file stream object, open the file and reading line by line */
	std::ifstream infile("example.txt");

	std::string line;
	while (std::getline(infile, line)) {
		std::cout << line << std::endl;
	}

	infile.close();

	return 0;
}

/*
** The `std::ofstream` class is used to create files and write to them.
** In our example we create a file called `example.txt` 
** and write the string `Hello, world!` to it.
**
** The `std::ifstream` class is used to read from files.
** In our example we read two integers from the file 
** `numbers.txt` and print them to the console.
**
** In the example: `std::ifstream infile("example.txt")` 
** we are reading line by line from a file.
** We use the `std::getline()` function to read a line from the file and store it in a string.
** The `std::getline()` function returns a reference to the input stream,
** which evaluates to `true` if the read operation was successful and `false` otherwise.
** This allows us to use the `std::getline()` function in a `while` loop condition.
*/
