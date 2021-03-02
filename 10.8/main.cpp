/* 10.8 LAB 4: Classes (Distance)
Distance Class
The Distance class will represent a distance in some number of feet and inches. This Distance object must always be positive and never contain an inch value greater than or equal to 12 (12 inches equals 1 foot). It is your job, as the engineer/designer of this Distance class to make sure this is always true.

Separate Files
As is commonly done when designing a class, you are to separate your class from the program that will use the class. You will need the following 3 files:

main.cpp: contains the main function and any other global functions used to test your Distance class.
Distance.h: the Distance class header (aka interface) file. Contains the declaration of the Distance class.
Distance.cpp: the Distance class implementation file. Contains the implementations of all Distance member functions.
You will submit all 3 files, main.cpp, Distance.h and Distance.cpp. Here is the Distance.h file you MUST submit:

DO NOT CHANGE THIS FILE IN ANY WAY

Use this main.cpp file for submission. You will want to add your own unit tests of the other public functions, but do not add them to the main.cpp file you are submitting.

Given this main function, if your constructors and operator functions are working correctly, your output will look like:

d1: 0' 0"
d2: 2' 5.9"
d3: 0' 3.75"
d4: 6' 7.34"
d5: 8' 4"
d4 + d5: 14' 11.34"
d2 + d4: 9' 1.24"
d3 - d1: 0' 3.75"
d1 - d3: 0' 3.75"
d4 - d2: 4' 1.44"
d2 - d4: 4' 1.44"
d4 - d5: 1' 8.66"
d5 - d2: 5' 10.1" */

#include <iostream>

using namespace std;

#include "Distance.cpp"

int main() {

	Distance d1;
	cout << "d1:" << d1 << endl;

	Distance d2 = Distance(2, 5.9);
	Distance d3 = Distance(3.75);
	cout << "d2: " << d2 << endl;
	cout << "d3: " << d3 << endl;

	// Test init helper function.
	Distance d4 = Distance(5, 19.34);
	Distance d5 = Distance(100);
	cout << "d4: " << d4 << endl;
	cout << "d5: " << d5 << endl;

	// Test add (<12 inches).
	cout << "d4 + d5: " << (d4 + d5) << endl;
	// Test add (>12 inches).
	cout << "d2 + d4: " << (d2 + d4) << endl;

	// Test sub (0 ft).
	cout << "d3 - d1: " << (d3 - d1) << endl;
	// Test sub (0 ft, negative conversion).
	cout << "d1 - d3: " << (d1 - d3) << endl;

	// Test sub (positive ft & inch).
	cout << "d4 - d2: " << (d4 - d2) << endl;
	// Test sub (negative ft & inch).
	cout << "d2 - d4: " << (d2 - d4) << endl;

	// Test sub (negative ft, positive inch).
	cout << "d4 - d5: " << (d4 - d5) << endl;
	// Test sub (positive ft, negative inch).
	cout << "d5 - d2: " << (d5 - d2) << endl;

	return 0;
}
