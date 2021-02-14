#include <iostream>

using namespace std;

double mean(const double array[], int arraySize) {
	double sum = 0;
	for (int i = 0; i < arraySize; ++i) {
		sum = sum + array[i];
	}
	return sum / arraySize;
}

void display(const double array[], int arraySize) {
	for (int i = 0; i < arraySize - 1; ++i) {
		cout << array[i] << ", ";
	}
	cout << array[arraySize - 1];
}

void remove (double array[], int& arraySize, int index) {
	for (int i = index; i < arraySize - 1; ++i) {
		array[i] = array[i + 1];
	}
	arraySize = arraySize - 1;
}

int main() {
	
	int arraySize = 10;
	double myArray[10];
	cout << "Enter 10 values:" << endl;
	for (int i = 0; i < arraySize; ++i) {
		cin >> myArray[i];
	}
	cout << endl;
	cout << "Mean: " << mean(myArray, arraySize) << endl << endl;

	cout << "Enter index of value to be removed: ";
	int index;
	cin >> index;
	cout << endl;
	cout << "Before removing value: ";
	display(myArray, arraySize);
	cout << endl;
	cout << "After removing vlaue: ";
	remove(myArray, arraySize, index);
	display(myArray, arraySize);
	cout << endl;

	return 0;
}
