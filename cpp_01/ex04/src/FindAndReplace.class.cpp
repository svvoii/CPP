#include "../includes/FindAndReplace.class.hpp"

FindAndReplace::FindAndReplace() {
	return;
}

FindAndReplace::~FindAndReplace() {
	return;
}

/*
** Here we read the contents of the file and store it in the `_fileContentsBuffer`
*/
bool	FindAndReplace::getFileContents(std::string fileName) {

	std::ifstream input(fileName.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file\n";
		return false;
	}

	std::string line;
	while (std::getline(input, line)) {
		_fileContentsBuffer += line + '\n';
	}

	input.close();

	return true;
}

/*
** This will read the contents of the `_fileContentsBuffer` and replace s1 with s2 in it
** and store the result in the `_output` buffer
** 
** `src.find(s1, pos)` will return the position of the first occurrence
** of `s1` in `src` starting from `pos`
*/
bool	FindAndReplace::replace(std::string const s1, std::string const s2) {

	std::string &src = _fileContentsBuffer;
	size_t pos = 0;

	while ((pos = src.find(s1, pos)) != std::string::npos) {

		src = src.substr(0, pos) + s2 + src.substr(pos + s1.length());
		pos += s2.length();
	}
	_output = src;

	return true;
}

/*
** This will write the contents of the `_output` buffer into the output file
*/
bool	FindAndReplace::writeToFile(std::string fileName) {

	std::ofstream output(fileName.c_str());
	if (!output.is_open()) {
		std::cerr << "Error: Could not create output file\n";
		return false;
	}
	output << _output;
	output.close();

	return true;
}
