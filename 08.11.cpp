/* 8.11 Lab 2 (Part 2) - File I/O Characters
Implement the function charCnt. charCnt is passed in a name of a file and a single character (type char). This function should open the file, count the number of times the character is found within the file, close the file, and then return the count.

If the file does not exist, this function should output an error message and then call the exit function to exit the program with an error value of 1. */

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string, char);

int main() {
	string filename;
	char ch;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;
	cout << "Enter a character: ";
	cin >> ch;
	cout << endl;

	cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

	return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch) {
	int count = 0;
	char c;
	ifstream file;

	file.open(filename.c_str());
	if (!file.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	while (file >> c) {
		if (c == ch) {
			++count;
		}
	}
	if (file.eof()) {
		file.close();
	}
	return count;
}
