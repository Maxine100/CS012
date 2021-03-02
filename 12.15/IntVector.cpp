#include "IntVector.h"

IntVector::IntVector() {
	sz = 0;
	cap = 0;
	data = 0;
}

IntVector::IntVector(unsigned size, int value) {
	sz = size;
	cap = size;
	int arr[sz];
	for (unsigned i = 0; i < sz; ++i) {
		arr[i] = value;
	}
	data = arr;
}

IntVector::~IntVector() {

}

unsigned IntVector::size() const {
	return sz;
}

unsigned IntVector::capacity() const {
	return cap;
}

bool IntVector::empty() const {
	if (sz == 0) {
		return true;
	}
	return false;
}

const int& IntVector::at(unsigned index) const {
	if (index >= sz) {
		throw out_of_range("intVector::at_range_check");
	}
	return data[index];
}

const int& IntVector::front() const {
	return data[0];
}

const int& IntVector::back() const {
	int arrSize = sz;
	--arrSize;
	return data[arrSize];
}
