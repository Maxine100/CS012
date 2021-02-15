#include "IntVector.h"

IntVector::IntVector() {
	sz = 0;
	cap = 0;
	data = 0;
}

IntVector::IntVector(unsigned size, int value) {
	sz = size;
	cap = size;
	data = new int[sz];
	for (unsigned i = 0; i < sz; ++i) {
		data[i] = value;
	}
}

IntVector::~IntVector() {
	delete[] data;
	return;
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
	else {
		return false;
	}
}

const int& IntVector::at(unsigned index) const {
	if (index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	else {
		return data[index];
	}
}

int& IntVector::at(unsigned index) {
	if (index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	else {
		return data[index];
	}
}

void IntVector::insert(unsigned index, int value) {
	if (index > sz) {
		throw out_of_range("IntVector::insert_range_check");
	}
	else {
		if ((sz + 1) > cap) {
			expand();
		}
		sz = sz + 1;
		if (index > sz) {
			throw out_of_range("IntVector::insert_range_check");
		}
		else {
			for (unsigned i = index; i < (sz - 1); ++i) {
				data[i + 1] = data[i];
			}
			data[index] = value;
		}
	}
}

void IntVector::erase(unsigned index) {
	if (index >= sz) {
		throw out_of_range("IntVector::erase_range_check");
	}
	else {
		for (unsigned i = index; i < sz; ++i) {
			data[i] = data[i + 1];
		}
	}
	sz = sz - 1;
}

const int& IntVector::front() const {
	return data[0];
}

int& IntVector::front() {
	return data[0];
}

const int& IntVector::back() const {
	return data[sz - 1];
}

int& IntVector::back() {
	return data[sz - 1];
}

void IntVector::assign(unsigned n, int value) {
	if (n > cap) {
		unsigned newCap;
		if (n > (cap * 2)) {
			newCap = n;
		}
		else if (n > cap) {
			newCap = cap * 2;
		}
		delete []data;
		data = new int[newCap];
		cap = newCap;
	}

	sz = n;

	for (unsigned i = 0; i < sz; ++i) {
		data[i] = value;
	}
}

void IntVector::push_back(int value) {
	if ((sz + 1) > cap) {
		expand();
		sz = sz + 1;
	}
	else {
		sz = sz + 1;
	}

	data[sz - 1] = value;
}

void IntVector::pop_back() {
	sz = sz - 1;
}

void IntVector::clear() {
	sz = 0;
}

void IntVector::resize(unsigned size, int value) {
	if (size > cap) {
		if (size > (cap * 2)) {
			expand(size - cap);
		}
		else if (size > cap) {
			expand();
		}
	}

	if (size < sz) {
		sz = size;
	}
	else if (sz < size) {
		for (unsigned i = sz; i < size; ++i) {
			data[i] = value;
		}
		sz = size;
	}
}

void IntVector::reserve(unsigned amount) {
	if (amount > cap) {
		cap = amount;
	}
}

void IntVector::expand() {
	if (cap == 0) {
		cap = 1;
		data = new int[cap];
		return;
	}
	else {
		cap = cap * 2;
		int *ptr = data;
		data = new int[cap];
		for (unsigned i = 0; i < sz; ++i) {
			data[i] = ptr[i];
		}
		delete []ptr;
	}
}

void IntVector::expand(unsigned amount) {
	cap = cap + amount;
	int *ptr = data;
	data = new int[cap];
	for (unsigned i = 0; i < sz; ++i) {
		data[i] = ptr[i];
	}
	delete []ptr;
}
