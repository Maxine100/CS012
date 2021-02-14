#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.cpp"

int main() {
	
	IntVector item1;
	cout << "item1's size: " << item1.size() << endl;
	cout << "item1's capacity: " << item1.capacity() << endl;
	if (item1.empty()) {
		cout << "item1 is empty." << endl;
	}
	else {
		cout << "item1 is not empty." << endl;
	}

	IntVector item2(5, 123);
	cout << "item2's size: " << item2.size() << endl;
	cout << "item2's capacity: " << item2.capacity() << endl;
	if (item2.empty()) {
		cout << "item2 is empty." << endl;
	}
	else {
		cout << "item2 is not empty." << endl;
	}
	
	int index;
	cout << "Enter index: ";
	cin >> index;
	cout << "item2 at index " << index << " is " << item2.at(index) << endl;

	return 0;
}
