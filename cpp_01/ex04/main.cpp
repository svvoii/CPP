#include "includes/FindAndReplace.class.hpp"

/*
** This program must take three arguments:
** 1. The name of a file
** 2. A string `to find`
** 3. A string to `replace with` the first `to find`.
*/
int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Error: Invalid number of arguments\n";
		std::cerr << "Usage:" << std::endl; 
		std::cerr << "./Find_and_replace <filename> <string to find> <string to replace with>\n";
		return 1;
	}

	FindAndReplace findAndReplace;

	if (!findAndReplace.getFileContents(argv[1]))
		return 1;
	if (!findAndReplace.replace(argv[2], argv[3]))
		return 1;
	if (!findAndReplace.writeToFile(std::string(argv[1]) + ".replace"))
		return 1;

	return 0;
}

/*
int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Error: Invalid number of arguments\n";
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file\n";
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string outFile = std::string(argv[1]) + ".replace";

	// Using separate buffer to copy the file contents
	std::string buffer;
	std::string line;
	while (std::getline(input, line)) {
		buffer += line + '\n';
	}

	// Replacing all occurrences of s1 with s2
	size_t pos = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos) {
		buffer = buffer.substr(0, pos) + s2 + buffer.substr(pos + s1.length());
		pos += s2.length();
	}

	// Writing the buffer with replaced contents to the output file
	std::ofstream output(outFile.c_str());
	if (!output.is_open()) {
		std::cerr << "Error: Could not create output file\n";
		return 1;
	}
	output << buffer;

	input.close();
	output.close();

	return 0;
}
*/
