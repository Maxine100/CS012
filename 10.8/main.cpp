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

	Distance d4 = Distance(5, 19.34);
	Distance d5 = Distance(100);
	cout << "d4: " << d4 << endl;
	cout << "d5: " << d5 << endl;

	cout << "d4 + d5: " << (d4 + d5) << endl;
	cout << "d2 + d4: " << (d2 + d4) << endl;

	cout << "d3 - d1: " << (d3 - d1) << endl;
	cout << "d1 - d3: " << (d1 - d3) << endl;

	cout << "d4 - d2: " << (d4 - d2) << endl;
	cout << "d2 - d4: " << (d2 - d4) << endl;

	cout << "d4 - d5: " << (d4 - d5) << endl;
	cout << "d5 - d2: " << (d5 - d2) << endl;

	return 0;
}
