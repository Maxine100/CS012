#include <iostream>

using namespace std;

class Date {
	private:
		unsigned day;
		unsigned month;
		string monthName;
		unsigned year;
	
	public:
		Date() {
			day = 1;
			month = 1;
			monthName = "January";
			year = 2000;
		}

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
		Date(unsigned m, unsigned d, unsigned y) {
			if (m > 12 || m < 1) {
				if ( m > 12) {
					m = 12;
					if (d > 31) {
						d = 31;
					}
					else if (d < 1) {
						d = 1;
					}
				}
				else if (m < 1) {
					m = 1;
					if (d > 31) {
						d = 31;
					}
					else if (d < 1) {
						d = 1;
					}
				}
				cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
			}
			else if (m >= 1 && m <= 12 && d > daysPerMonth(m, y)) {
				d = daysPerMonth(m, y);
				cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
			}
			else if (m >= 1 && m <= 12 && d < 1) {
				d = 1;
				cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
			}
			
			this->day = d;
			this->month = m;
			this->year = y;
			this->monthName = name(m);
		}

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
		Date(const string& mn, unsigned d, unsigned y) {
			if (mn == "January" || mn == "january" || mn == "February" || mn == "february" || mn == "March" || mn == "march" || mn == "April" || mn == "april" || mn == "May" || mn == "may" || mn == "June" || mn == "june" || mn == "July" || mn == "july" || mn == "August" || mn == "august" || mn == "September" || mn == "september" || mn == "October" || mn == "october" || mn == "November" || mn == "november" || mn == "December" || mn == "december") {
				if (d > daysPerMonth(number(mn), y)) {
					d = daysPerMonth(number(mn), y);
					cout << "Invalid date values: Date corrected to " << number(mn) << "/" << daysPerMonth(number(mn), y) << "/" << y << "." << endl;
				}
				else if (d < 1) {
					d = 1;
					cout << "Invalid date values: Date corrected to " << number(mn) << "/1/" << y << "." << endl;
				}
				this->day = d;
				this->month = number(mn);
				this->monthName = mn;
				this->year = y;
			}
			if (mn != "January" && mn != "january" && mn != "February" && mn != "february" && mn != "March" && mn != "march" && mn != "April" && mn != "april" && mn != "May" && mn != "may" && mn != "June" && mn != "june" && mn != "July" && mn != "july" && mn != "August" && mn != "august" && mn != "September" && mn != "september" && mn != "October" && mn != "october" && mn != "November" && mn != "november" && mn != "December" && mn != "december") {
				cout << "invalid month name: the Date was set to 1/1/2000." << endl;
				this->day = 1;
				this->month = 1;
				this->monthName = name(1);
				this->year = 2000;
			}
		}

		void printNumeric() const {
			cout << month << "/" << day << "/" << year;
		}

		void printAlpha() const {
			cout << monthName << " " << day << ", " << year;
		}
		
	private:
		bool isLeap(unsigned y) const {
			if (y % 4 == 0) {
				if (y % 100 == 0) {
					if (y % 400 == 0) {
						return true;
					}
					else {
						return false;
					}
				}
				else {
					return true;
				}
			}
			else {
				return false;
			}
		}

		unsigned daysPerMonth(unsigned m, unsigned y) const {
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				return 31;
			}
			if (m == 4 || m == 6 || m == 9 || m == 1) {
				return 30;
			}
			if (m == 2) {
				if (isLeap(y)) {
					return 29;
				}
			}
			return 28;
		}

		string name(unsigned m) const {
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

		unsigned number(const string& mn) const {
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
};

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
