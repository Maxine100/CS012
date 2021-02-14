#include <iostream>

using namespace std;

class Data {
	private:
		unsigned day;
		unsigned month;
		string monthName;
		unsigned year;
	
	public:
		Date() {

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

		}

		void printNumeric() const {

		}

		void printAlpha() const {

		}
		
	private:
		bool isLeap(unsigned y) const {

		}

		unsigned daysPerMonth(unsigned m, unsigned y) const {

		}

		string name(unsigned m) const {

		}

		unsigned number(const string& mn) const {

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
	} else if (choice == 2) {
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
	} else {
	  return Date();
	}
}
