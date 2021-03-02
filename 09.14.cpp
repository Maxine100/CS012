/* 9.14 LAB 3: Classes (Rational)
Rational Numbers
It may come as a bit of a surprise when the C++ floating-point types (float, double), fail to capture a particular value accurately. Certainly double, which is usually stored as a 64-bit value, is far better than the old float, which is only 32 bits, but problems do arise. For example:

float n = 2.0;
float d = 3.0;
cout << precision(17);
cout << n / d << endl;
produces 0.6666668653488159, which is accurate to only 8 decimal places - a bit dirty for a discipline that prides itself on precision!

A solution that is often used when precision is of greatest importance and all of the numbers involved are going to be "rational" (that is, expressible as a 'ratio' of two integers - i.e. a fraction) is to use a custom data type - i.e. a class - that implements fractions, or "rational numbers". This is what you will do in this lab assignment.

Class Specification
Write a C++ program that performs the rational number operations addition, subtraction, multiplication and division on two fractions. The program should be written in a single file. You will need to design a "rational number" class named Rational whose value will be a fraction (e.g., 1/128, or 22/7), with appropriate constructors and member functions. A fraction will be specified as a numerator and a denominator - e.g. the pair (8, 109) represents the fraction 8/109. The member variables should be private and accessed using the accessor and mutator functions.

Constructors
Create 3 constructors:

a constructor with two parameters (numerator and denominator)
a constructor with one parameter (denominator set to 1)
a constructor with no parameters (0/1)
Accessor Functions
add
subtract
multiply
divide
display
Mutator Function
simplify
The following are a list of the rules of arithmetic for fractions:

(a/b) + (c/d) = (ad + bc) / (b*d)
(a/b) - (c/d) = (ad - bc) / (b*d)
(a/b) * (c/d) = (ac) / (bd)
(a/b) / (c/d) = (ad) / (cb)
Note that for this lab, when you perform an operation, you do not need to simplify the resulting fraction, i.e., 4/5 * 5/10 = 20/50. You should not simplify this to 2/5 at this point.

The display function should output the Rational object in the format:

n / d
The simplify function should divide the numerator and denominator by the greatest common divisor. This function should call the private helper function gcd to get the greatest common divisor. Feel free to use one of the gcd algorithms here: Euclidean algorithm

Required Class Interface
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};
Required main function
You must use this main function and global functions getRational and displayResult exactly as they are here. You may not change these functions at all. Copy-and-paste these into your main.cpp file and then add the Rational class.

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

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
      << "3 - 0 parameters (default)" << endl;
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

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
} */

#include <iostream>

using namespace std;

class Rational {
	private:
		int numerator;
		int denominator;
	
	public:
		Rational();
		explicit Rational(int);
		Rational(int, int);
		const Rational add(const Rational&) const;
		const Rational subtract(const Rational&) const;
		const Rational multiply(const Rational&) const;
		const Rational divide(const Rational&) const;
		void simplify();
		void display() const;

	private:
		int gcd(int, int) const;
};

Rational:: Rational() {
	numerator = 0;
	denominator = 1;
}
Rational:: Rational(int n) {
	numerator = n;
	denominator = 1;
}
Rational::Rational(int n, int d) {
			numerator = n;
			denominator = d;
		}
const Rational Rational::add(const Rational& rational) const {
	Rational sum;
	sum.numerator = this->numerator * rational.denominator + this->denominator * rational.numerator;
	sum.denominator = this->denominator * rational.denominator;
	return sum;
}
const Rational Rational::subtract(const Rational& rational) const {
	Rational difference;
	difference.numerator = this->numerator * rational.denominator - this->denominator * rational.numerator;
	difference.denominator = this->denominator * rational.denominator;
	return difference;
}
const Rational Rational::multiply(const Rational& rational) const {
	Rational product;
	product.numerator = this->numerator * rational.numerator;
	product.denominator = this->denominator * rational.denominator;
	return product;
}
const Rational Rational::divide(const Rational& rational) const {
	Rational quotient;
	quotient.numerator = this->numerator * rational.denominator;
	quotient.denominator = this->denominator * rational.numerator;
	return quotient;
}
void Rational::simplify() {
	int a = gcd(this->numerator, this->denominator);
	this->numerator = this->numerator / a;
	this->denominator = this->denominator / a;
}
void Rational::display() const {
	cout << this->numerator << " / " << this->denominator;
}
int Rational::gcd(int numerator, int denominator) const {
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
