#include <iostream>

using namespace std;

bool diophantine(int a, int b, int c, int& x, int& y) {

}

int main() {
	
	int a, b, c, x, y;

	cout << "Enter a b c" << endl;
	cin >> a >> b >> c;
	cout << endl;

	cout << "Result: ";
	if (diophantine(a, b, c, x, y)) {
		cout << x << " " << y << endl;
	}
	else {
		cout << "No solution!" << endl;
	}

	return 0;
}
