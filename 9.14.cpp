#include <iostream>

using namespace std;

class Rational {
	private:
		int numerator;
		int denominator;
	
	public:
		Rational() {
			numerator = 0;
			denominator = 1;
		}
		explicit Rational(int numer) {
			numerator = numer;
			denominator = 1;
		}
		Rational(int numer, int denom) {
			numerator = numer;
			denominator = denom;
		}
		const Rational add(const Rational& rational) const {
			Rational temp;
			temp.numerator = this->numerator * rational.denominator + this->denominator * rational.numerator;
			temp.denominator = this->denominator * rational.denominator;
			return temp;
		}
		const Rational subtract(const Rational& rational) const {
			Rational temp;
			temp.numerator = this->numerator * rational.denominator - this->denominator * rational.numerator;
			temp.denominator = this->denominator * rational.denominator;
			return temp;
		}
		const Rational multiply(const Rational& rational) const {
			Rational temp;
			temp.numerator = this->numerator * rational.numerator;
			temp.denominator = this->denominator * rational.denominator;
			return temp;
		}
		const Rational divide(const Rational& rational) const {
			Rational temp;
			temp.numerator = this->numerator * rational.denominator;
			temp.denominator = this->denominator * rational.numerator;
			return temp;
		}
		void simplify() {
			int a = gcd(numerator, denominator);
			int b = numerator / a;
			int c = denominator / a;

			this->numerator = b;
			this->denominator = c;
		}
		void display() const {
			cout << numerator << " / " << denominator;
		}

	private:
		int gcd(int numerator, int denominator) const {
			int a = numerator;
			int b = denominator;
			while (a != b) {
				if (b > a) {
					b = b - a;
				}
				else {
					a = a - b;
				}
			}
			return a;
		}
};

Rational getRational();
void displayResult(const string&, const Rational&, const Rational&, const Rational&);

int main() {

	Rational A, B, result;
	int choice;

	cout << "Enter Rational A:" << endl;
	A = getRational();
	cout << endl;

	cout << "Enter Rational B:" << endl;
	B = getRational();
	cout << endl;

	cout << "Enter Operation (1 - 4):" << endl
		<< "1 - Addition (A + B)" << endl
		<< "2 - Subtraction (A - B)" << endl
		<< "3 - Multiplication (A * B)" << endl
		<< "4 - Division (A / B)" << endl
		<< "5 - Simplify A" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		result = A.add(B);
		displayResult("+", A, B, result);
	} else if (choice == 2) {
		result = A.subtract(B);
		displayResult("-", A, B, result);
	} else if (choice == 3) {
		result = A.multiply(B);
		displayResult("*", A, B, result);
	} else if (choice == 4) {
		result = A.divide(B);
		displayResult("/", A, B, result);
	} else if (choice == 5) {
		A.simplify();
		A.display();
	} else {
		cout << "Unknown Operation";
	}
	cout << endl;

	return 0;
}

Rational getRational() {
	int choice;
	int numer, denom;

	cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
		<< "1 - 2 parameters (numerator & denominator)" << endl
		<< "2 - 1 parameter (numerator)" << endl
		<< "3 - 0 parameters (defult) " << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		cout << "numerator? ";
		cin >> numer;
		cout << endl;
		cout << "denominator? ";
		cin >> denom;
		cout << endl;
		return Rational(numer, denom);
	} else if (choice == 2) {
		cout << "numerator? ";
		cin >> numer;
		cout << endl;
		return Rational(numer);
	} else {
		return Rational();
	}
}

void displayResult(const string& op, const Rational& lhs, const Rational& rhs, const Rational& result) {
	cout << "(";
	lhs.display();
	cout << ") " << op << " (";
	rhs.display();
	cout << ")  = (";
	result.display();
	cout << ")";
}
