# include <iostream>
# include <string>
# include <sstream>
# include <fstream>

int main() {

	
	std::ofstream outFile("Quiz4_2.txt", std::ios::out);
	if (!outFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(1);
	}
	outFile << "A 123 456.789";
	outFile.close();

	// To read from a file
	std::ifstream inFile("Quiz4_2.txt", std::ios::in);
	if (!inFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(1);
	}
	char s1;
	int s2;
	double s3;
	inFile >> s1 >> s2 >> s3;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	inFile.close();


	std::stringstream iss;
	std::ifstream inFileStream("Quiz4_2.txt", std::ios::in);
	if (!inFileStream) {
		std::cerr << "File could not be opened" << std::endl;
		exit(1);
	}
	std::string str;
	iss << inFileStream.rdbuf();
	inFile.close();

	std::cout << iss.str();

	return 0;
}

/*

// File System
// To read and write data from/to a file, we will work with a string and a string stream
// a string is an array of characters
// a string stream is an object that handles string, e.g., to read/write a string to a file.
// there are two types of string stream objects: 1) Input Stream, 2) Output stream

int main() {
	//output stream
	std::ostringstream outputStr;
	std::string s1("Output: abc");
	double d = 123.456;
	outputStr << s1 << d << std::endl; // write s1 and d to an output string stream
	// line above is similar to 
	// std::cout << s1 << d << std::endl;
	// This means that instead of printing a string or a number directly out to the termina;/console screen
	// we will save the information in a variable (std::ostringstream outputStr)
	std::cout << outputStr.str(); // after saving the information in outputStr, we print it out onto a console.

	// input stream
	std::stringstream iss;
	std::string strvalues = " 32 240  2 1450"; // thsi can come from a text file
	iss.str(strvalues); // copy
	for (int n = 0; n < 4; n++) {
		int val;
		iss >> val; // each number will be copied over to int vale variable
		// each information in the stream separated by a space (default) or a deliminator (",",";") will be interpreted as a separate data
		// strvalues >> val; // error. I cannot send a string "32 240 2 1450" to an integer
		std::cout << val << std::endl;
	}

	// Using stremas with a file
	// Instead of using std::cout, we will create a variable that points to a file in your harddisk.
	std::ofstream outFile("data.dat", std::ios::out); // std::ios::out specifies that this file is for writing only
	if (!outFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(1);
	}
	double pi = 3.14159265358970323846264338327950266;
	outFile << "PI is: " << pi;
	outFile.close();

	// To read from a file
	std::ifstream inFile("data.dat", std::ios::in); // std::ios::in opens the file as read only
	if (!inFile) {
		std::cerr << "File could not be opened" << std::endl; 
		exit(1);  
	}
	double pi1;
	std::string s3, s4;
	inFile >> s3 >> s4 >> pi1; // copy data from a file to each of these variables
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << pi1 << std::endl;
	inFile.close();


	return 0;
}

*/