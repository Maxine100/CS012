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

	return 0;
}
