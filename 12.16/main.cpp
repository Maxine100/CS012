#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.cpp"

int main() {

	IntVector vec(5, 3);
	vec.insert(5, 4);
	for (unsigned i = 0; i < vec.size(); ++i) {
		cout << vec.at(i) << endl;
	}

	// Calls default constructor
	IntVector item1;

	// Calls size, capacity, and empty functions.
	cout << "item1's size: " << item1.size() << endl;
	cout << "item1's capacity: " << item1.capacity() << endl;
	if (item1.empty()) {
		cout << "item1 is empty." << endl;
	}
	else {
		cout << "item1 is not empty." << endl;
	}

	// Calls other constructor.
	IntVector item2(4, 100);

	// Calls size, capacity, and empty functions.
	cout << "item2's size: " << item2.size() << endl;
	cout << "item2's capacity: " << item2.capacity() << endl;
	if (item2.empty()) {
		cout << "item2 is empty." << endl;
	}
	else {
		cout << "item2 is not empty." << endl;
	}

	// Calls at() function.
	int index;
	cout << "Enter index of wanted element for item2: ";
	cin >> index;
	cout << item2.at(index) << endl;

	return 0;
}
