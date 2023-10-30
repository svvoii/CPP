#ifndef FINDANDREPLACE_CLASS_HPP
#define FINDANDREPLACE_CLASS_HPP

# include <iostream>
# include <fstream>
# include <string>

/*
** The purpose of this class is to read the contents of a file and 
** replace all occurrences of a string `s1` with string `s2`.
*/
class FindAndReplace {
	private:
		std::string _line;
		std::string _fileContentsBuffer;
		std::string _output;
		
	public:
		FindAndReplace();
		~FindAndReplace();

		/* This will read the contents of the file and store it in the _fileContentsBuffer */
		bool	getFileContents(std::string fileName);

		/* This will read the contents of the src buffer and replace s1 with s2 in it */
		bool	replace(std::string const s1, std::string const s2);

		/* This will write the contents of the _output buffer to the file */
		bool	writeToFile(std::string fileName);
};

#endif
