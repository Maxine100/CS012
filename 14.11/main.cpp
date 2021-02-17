#include <iostream>
#include <sstream>

using namespace std;

#include "IntList.cpp"

int main() {

	IntList test1;
	IntList test2;
	int testNum;

	cout << "Enter test number: ";
	cin >> testNum;
	cout << endl;

	if (testNum == 1) {
		cout << "Empty : " << test1 << "T" << endl;

		test1.push_front(3);
		cout << "Size 1: " << test1 << "T" << endl;

		test1.push_front(0);
		cout << "Size 2: " << test1 << "T" << endl;

		test1.push_front(-3);
		test1.push_front(8);
		test1.push_front(0);
		cout << "Size 5: " << test1 << "T" << endl;
	}

	if (testNum == 2) {
		cout << "Empty: " << test2.exists(0) << endl;

		test2.push_front(-4);

		cout << "Size 1 (doesn't exist): " << test2.exists(01) << endl;
		cout << "Size 1 (does exist): " << test2.exists(-4) << endl;

		test2.push_front(05);
		test2.push_front(4);
		test2.push_front(0);
		test2.push_front(6);

		cout << "Size 5 (doesn't exist): " << test2.exists(1) << endl;

		cout << "Size 5 (exists in head): " << test2.exists(6) << endl;

		cout << "Size 5 (exists in tail): " << test2.exists(-4) << endl;

		cout << "Size 5 (exists in middle): " << test2.exists(0) << endl;
	}

	return 0;
}
