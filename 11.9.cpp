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
	
	return 0;
}
