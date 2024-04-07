# include <iostream>
# include <regex>
# include <string>

// Note 4/4:
// Regular Expression (Regex)
// Regex is used for searching for a specific keyword within a string.
// It cna be used for checking if an input string (texts read from a file)
// certain keyword.
// Regex exists in almost every programming language, not only C/C++
// Regex has iits own syntax, which we will look into in this class today.
// 
// In terms of coding (using regex in C/C++ code),
// the code follows the same procedure
// 1) You have a string whether from a variable declaration or read a string from a file
// 2) Define a regualr expression that can search fro your certain keyword or keywords
// 3) The program will tell you if your string containts that information
// 4) You can do whatever you want with that information
// 
// Regex will have aa weird syntax but it is faster than going over each character in the string
//

int main() {
	// define a string or a sentence, you want to search for a keyword
	std::string mystr = "She sells_sea shells in the sear shore";

	// regex expression for pattern to be search
	std::regex regexp("s[a-z_]+");
	// s[a-z_]+  says 
	// s: for the first letter, we want to search for a keyword that starts with a letter 's' (case_sensitive)
	// [a-z_]: for the second letter, we want to search for a keyword that starts with any letter from a-z or an underscore
	//

	// flag type for determining the matching behavior (in this case on string objects)
	std::smatch m;

	// regex_search that seraches pattern regex
	regex_search(mystr, m, regexp);

	// print out the search result
	std::cout << "String that matches the pattern: " << std::endl;
	for (auto x : m)
		std::cout << x << " ";

	return 0;
}