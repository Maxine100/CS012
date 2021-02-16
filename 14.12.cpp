#include <iostream>

using namespace std;

int gcd(int& a, int& b) {
	if (a == b) {
		return a;
	}
	if (a > b) {
		int c = a - b;
		return gcd(c, b);
	}
	if (b > a) {
		int d = b - a;
		return gcd(a, d);
	}
	return 0;
}

bool diophantine(int a, int b, int c, int& x, int& y) {
	if (c % gcd(a, b) != 0) {
		return false;
	}
	else {
		if (a % b == 0) {
			x = 0;
			y = c / b;
			return true;
		}
		else {
			int r, u, v;
			r = a % b;
			diophantine(b, r, c, u, v);
			x = v;
			y = u - (a / b) * x;
			return true;
		}
	}
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
