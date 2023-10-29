#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

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

	std::ofstream output(outFile.c_str());
	if (!output.is_open()) {
		std::cerr << "Error: Could not create output file\n";
		return 1;
	}

	std::string line;
	size_t pos = 0;
	while (std::getline(input, line)) {
		std::ostringstream newLine;
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			newLine << line.substr(pos, pos - line.length());
			newLine << s2;
			pos += s1.length();
		}
		// The error is here
		newLine << line.substr(pos);
		output << newLine.str() << '\n';
	}

	input.close();
	output.close();

	return 0;
}
