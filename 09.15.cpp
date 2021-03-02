/* 9.15 PROGRAM 2: Classes (Date)
Collaboration Policy Reminder
You may not use code from any source (another student, a book, online, etc.) within your solution to this PROGRAM. In fact, you may not even look at another student's solution or partial solution to this PROGRAM. You also may not allow another student to look at any part of your solution to this exercise. You should get help on this assignment by coming to the instructor's or TA's office hours or by posting questions on Piazza (you still must not post assignment code publicly on Piazza.)

Problem Definition
Build a Date class and a main function to test it.

Specifications
Below is the interface for the Date class: it is our "contract" with you: you have to implement everything it describes. The comments in the interface below should be sufficient for you to understand the project (use these comments in your Date declaration), without the need of any further documentation. But of course, as always, you can ask us any questions you may have on Piazza.


Note: Placing the error messages into the constructors like is not necessarily a good way to handle constructor errors, but until you learn about exceptions in CS 14, it's the best we can do.

Private Member Functions
The functions declared private above, isLeap, daysPerMonth, name, number, are helper functions - member functions that will never be needed by a user of the class, and so do not belong to the public interface (which is why they are "private"). They are, however, needed by the interface functions (public member functions), which use them to test the validity of arguments and construct valid dates. For example, the constructor that passes in the month as a string will call the number function to assign a value to the unsigned member variable month.

isLeap: The rule for whether a year is a leap year is:

(year % 4 == 0) implies leap year
except (year % 100 == 0) implies NOT leap year
except (year % 400 == 0) implies leap year
So, for instance, year 2000 is a leap year, but 1900 is NOT a leap year. Years 2004, 2008, 2012, 2016, etc. are all leap years. Years 2005, 2006, 2007, 2009, 2010, etc. are NOT leap years.

Output Specifications
Read the specifications for the print function carefully. The only cout statements within your Date member functions should be:

the "Invalid Date" warnings in the constructors
in your two print functions

Required Main Function
You must use this main function and global function getDate as they are here. You may not change these functions at all. Copy-and-paste these into your main.cpp file and then add the Date class. */

#include <iostream>

using namespace std;

class Date {
	private:
		unsigned day;
		unsigned month;
		string monthName;
		unsigned year;
	
	public:
		// creates the date January 1st, 2000.
		Date();


		/* parameterized constructor: month number, day year
		   - e.g. (3, 1, 2010) will construct the date March 1st, 2010
		
		   If any of the arguments are invalid (e.g. 15 for month or 32 for day)
		   then the constructor will construct instead a valid Date as close
		   as possible to the arguments provided - e.g. in above example,
		   Date(15, 32, 2010), the Data would be corrected to Dec 31st, 2010.
		   In case of such invalid input, the constructor will issue a console error massage:

		   Invalid date values: Data corrected to 12/31/2010.
		   (with a newline at the end).
		*/
		Date(unsigned m, unsigned d, unsigned y);

		/* parameterized constructor: month name, day, year
		    - e.g. (December, 15, 2012) will construct the date December 15th, 2012

		    If the constructor is unable to recognize the string argument as a valid month name,
		    then it will issue a console error message:
		
		    Invalid month name: the Date was set to 1/1/2000.
		    (with a newline at the end).
		
		    If the day argument is invalid for the given month (but the month name was valid),
		    then the constructor will handle this error in the same manner as the other
		    parameterized constructor.

		    This constructor will recognize both "december" and "December"
		    as month name.
		*/
		Date(const string& mn, unsigned d, unsigned y);
		

		/* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
		  Does not output a newline at the end.
        	*/
		void printNumeric() const;


		/* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
		  The first letter of the month name is upper case, and the month name is
		  printed in full - January, not Jan, jan, or january. 
		  Does not output a newline at the end.
		*/
		void printAlpha() const;
		
	private:
		
		/* Returns true if the year passed in is a leap year, otherwise returns false.
		*/
		bool isLeap(unsigned y) const;


		/* Returns number of days allowed in a given month
		  -  e.g. daysPerMonth(9, 2000) returns 30.
		  Calculates February's days for leap and non-­leap years,
		  thus, the reason year is also a parameter.
		*/
		unsigned daysPerMonth(unsigned m, unsigned y) const;

		/* Returns the name of a given month
		  - e.g. name(12) returns the string "December"
		*/
		string name(unsigned m) const;

		/* Returns the number of a given named month
		  - e.g. number("March") returns 3
		*/
		unsigned number(const string& mn) const;
};

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->monthName = "January";
	this->year = 2000;
	}
Date::Date(unsigned m, unsigned d, unsigned y) {
	if (m < 1) {
		this->month = 1;
		this->monthName = "January";
	}
	else if (m > 12) {
		this->month = 12;
		this->monthName = "December";
	}
	else {
		this->month = m;
		this->monthName = name(this->month);
	}
	if (d < 1) {
		this->day = 1;
	}
	else if (d > daysPerMonth(this->month, y)) {
		this->day = daysPerMonth(this->month, y);
	}
	else {
		this->day = d;
	}
	this->year = y;
	if (m < 1 || m > 12 || d < 1 || d > daysPerMonth(this->month, y)) {
		cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
	}
}
Date::Date(const string& mn, unsigned d, unsigned y) {
	if (mn != "January" && mn != "january" && mn != "February" && mn != "february" && mn != "March" && mn != "march" && mn != "April" && mn != "april" && mn != "May" && mn != "may" && mn != "June" && mn != "june" && mn != "July" && mn != "july" && mn != "August" && mn != "august" && mn != "September" && mn != "september" && mn != "October" && mn != "october" && mn != "November" && mn != "november" && mn != "December" && mn != "december") {
	cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
	this->month = 1;
	this->monthName = "January;
	this->day = 1;
	this->year = 2000;
	}
	else {
		this->month = number(mn);
		this->monthName = name(this->month);
		this->year = y;
		if (d > daysPerMonth(this->month, this->year)) {
			this->day = daysPerMonth(this->month, this->year);
			cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "/" << endl;
		}
		else if (d < 1) {
			this->day = 1;
			cout << "Invalid date values: Date corrected to " << month << "/" << this->day << "/" << this->year << "/" << endl;
		}
		else {
			this->day = d;
		}
	}
}
void Date::printNumeric() const {
	cout << this->month << "/" << this->day << "/" << this->year;
}
void Date::printAlpha() const {
	cout << this->monthName << " " << this->day << ", " << this->year;
}
bool Date::isLeap(unsigned y) const {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			return false;
		}
		return true;
	}
	return false;
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		return 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	else {
		if (isLeap(y)) {
			return 29;
		}
		return 28;
	}
}
string Date::name(unsigned m) const {
	if (m == 1) {
		return "January";
	}
	else if (m == 2) {
		return "February";
	}
	else if (m == 3) {
		return "March";
	}
	else if (m == 4) {
		return "April";
	}
	else if (m == 5) {
		return "May";
	}
	else if (m == 6) {
		return "June";
	}
	else if (m == 7) {
		return "July";
	}
	else if (m == 8) {
		return "August";
	}
	else if (m == 9) {
		return "September";
	}
	else if (m == 10) {
		return "October";
	}
	else if (m == 11) {
		return "November";
	}
	return "December";
}
unsigned Date::number(const string& mn) const {
	if (mn == "January" || mn == "january") {
		return 1;
	}
	else if (mn == "February" || mn == "february") {
		return 2;
	}
	else if (mn == "March" || mn == "march") {
		return 3;
	}
	else if (mn == "April" || mn == "april") {
		return 4;
	}
	else if (mn == "May" || mn == "may") {
		return 5;
	}
	else if (mn == "June" || mn == "june") {
		return 6;
	}
	else if (mn == "July" || mn == "july") {
		return 7;
	}
	else if (mn == "August" || mn == "august") {
		return 8;
	}
	else if (mn == "September" || mn == "september") {
		return 9;
	}
	else if (mn == "October" || mn == "october") {
		return 10;
		}
	else if (mn == "November" || mn == "november") {
		return 11;
	}
	return 12;
}

Date getDate();

int main() {

	Date testDate;
	testDate = getDate();
	cout << endl;
	cout << "Numeric: ";
	testDate.printNumeric();
	cout << endl;
	cout << "Alpha:   ";
	testDate.printAlpha();
	cout << endl;

	return 0;
}

Date getDate() {
	int choice;
	unsigned monthNumber, day, year;
	string monthName;

	cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
		<< "1 - Month Number" << endl
		<< "2 - Month Name" << endl
		<< "3 - default" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		cout << "month number? ";
		cin >> monthNumber;
		cout << endl;
		cout << "day ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthNumber, day, year);
	}
	else if (choice == 2) {
		cout << "month name? ";
		cin >> monthName;
		cout << endl;
		cout << "day? ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthName, day, year);
	}
	else {
		return Date();
	}
}
