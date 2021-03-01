/* 8.10 LAB 2 (Part 1): File I/O - Sum of integers
Implement the function fileSum. fileSum is passed in a name of a file. This function should open the file, sum all of the integers within this file, close the file, and then return the sum.

If the file does not exist, this function should output an error message and then call the exit function to exit the program with an error value of 1. */

#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {
	string filename;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	cout << endl;
	cout << "Sum: " << fileSum(filename) << endl;

	return 0;
}

// Place fileSum implementation here
int fileSum(string filename) {
	ifstream file;
	int num;
	int sum = 0;

	file.open(filename.c_str());
	if (!file.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	while (file >> num) {
		sum = sum + num;
	}
	if (file.eof()) {
		file.close();
	}
	return sum;
}
