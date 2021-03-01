/* 8.12 PROGRAM 1: Calculating Coefficient Of Lift
For this PROGRAM you will calculate the coefficient of lift for a given flight-path angle based on wind tunnel data stored in a file.

PROGRAM Steps
Ask the user for the name of file that contains the wind tunnel data.
Read wind-tunnel data into two parallel vectors, one vector stores the flight-path angle and the other stores the corresponding coefficient of lift for that angle. Both vectors should store doubles.
Ask the user for a flight-path angle. If the angle is within the bounds of the data set, the program should then use linear interpolation (see explanation of linear interpolation below) to compute the corresponding coefficient of lift and output it.
Finally, ask the user if they want to enter another flight-path angle. Repeat steps 3 and 4 if they answer yes, otherwise end the program if they answer no.
For linear interpolation to work, the flight-path angles in the data file must be in ascending order. If the flight-path angles are not in ascending order, your program will need to sort them before implementing Step 3.

Linear Interpolation
The wind-tunnel test data consists of some number of tested flight-path angles and their corresponding coefficient of lift. Using this data, we can estimate, using linear interpolation, the coefficient of lift for a flight-path angle within the bounds of the data set, even if that particular flight-path angle was not tested. If we want to find the coefficient of lift for flight-path angle b, we find flight-path angles a and c such that

a < b < c

Obviously, if flight-path b already exists in the given data set, then you do not need to use linear interpolation. However, if it doesn't exist, then linear interpolation assumes a straight line exists between f(a) and f(c). (In this case, f(a) is the coefficient of lift for flight-path angle a and f(c) is the coefficient of lift for flight-path angle c.) To find f(b), use the formula:

f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

Modular Programming
You must implement and use at least the following functions:

readData: passes in the name of a file and two vectors (double) and stores in the first vector the flight-path angles (first column) and in the second vector the corresponding coefficients of lift (2nd column). If the file does not open properly, this function should output an error message and then call the exit function passing it an exit value of 1.
interpolation: passes in the requested flight-path angle along with the 2 vectors of data (flight-path angles and corresponding coefficients of lift) and returns the corresponding coefficient of lift.
isOrdered: passes in the vector of flight-path angles and returns true if it stores the angles are in ascending order, otherwise returns false.
reorder: passes in both vectors of data and then reorders the data so that the flight-path angles are in ascending order while maintaining the correspondence between the flight-path angles and their corresponding coefficients of lift.
Here are the prototypes you must use for these functions:

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

Data File Format
The data file will have on each line, one flight-path angle (in degrees), a space, and then the corresponding coefficient of lift. See the following file examples, tunnel1.dat and tunnel2.dat. You must create these 2 files for testing your program on your own, however, you will only submit your main.cpp file. Use these files to help you test your program, but do not assume these will be the only files we will test your program with. In other words, when testing your program you should also make up your own data files. You should try to come up with data files that will break your program if it doesn't follow all of the given specifications. That's what we will be doing when grading it.

tunnel1.dat

-4.0 -0.182
-2.0 -0.056
0.0 0.097
2.0 0.238
4.0 0.421
6.0 0.479
8.0 0.654
10.0 0.792
12.0 0.924
14.0 1.035
15.0 1.076
16.0 1.103
17.0 1.120
18.0 1.121
19.0 1.121
20.0 1.099
21.0 1.059
tunnel2.dat

-2 -0.056
21 1.059
4 0.421
2 0.238
20 1.099
12 0.924
6 0.479
-4 -0.182
8 0.654
10 0.792
0 0.097
14 1.035
16 1.103
18 1.121
15 1.076
19 1.121
17 1.120 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string&, vector<double>&, vector<double>&);
double interpolation(double, const vector<double>&, const vector<double>&);
bool isOrdered(const vector<double>&);
void reorder(vector<double>&, vector<double>&);

int main() {
	
	string filename;
	vector<double> angles;
	vector<double> lift;
	cout << "Enter name of input data file:" << endl;
	cin >> filename;
	cout << endl;
	readData(filename, angles, lift);
	reorder(angles, lift);
	int fPA;
	cout << "Enter flight path angle: ";
	cin >> fPA;
	cout << interpolation(fPA, angles, lift) << endl;
	
	return 0;
}

void readData(const string& filename, vector<double>& angles, vector<double>& lift) {
	ifstream file;
	double fPA, cOL;
	file.open(filename);
	if (!file.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	while (file >> fPA >> cOL) {
		angles.push_back(fPA);
		lift.push_back(cOL);
	}
}
double interpolation(double angle, const vector<double>& angles, const vector<double>& lift) {
	unsigned i;
	int j;
	for (i = 0; i < angles.size(); ++i) {
		if (angles.at(i) == angle) {
			return lift.at(i);
		}
		if (angles.at(i) > angle) {
			j = i - 1;
			break;
		}
	}
	return lift.at(j) + (angle - angles.at(j)) / (angles.at(i) - angles.at(j)) * (lift.at(i) - lift.at(j));
}
bool isOrdered(const vector<double>& angles) {
	if (angles.size() > 0) {
		for (unsigned i = 0; i < angles.size() - 1; ++i) {
			for (unsigned j = 1; j < angles.size() - 1; ++j) {
				if (angles.at(j) > angles.at(j + 1)) {
					return false;
				}
			}
		}
	}
	return true;
}
void reorder(vector<double>& angles, vector<double>& lift) {
	if (!isOrdered(angles)) {
		for (unsigned i = 0; i < angles.size() - 1; ++i) {
			for (unsigned j = 0; j < angles.size() - 1; ++j) {
				if (angles.at(j) > angles.at(j + 1)) {
					double tempfPA = angles.at(j);
					angles.at(j) = angles.at(j + 1);
					angles.at(j + 1) = tempfPA;
					double tempcOL = lift.at(j);
					lift.at(j) = lift.at(j + 1);
					lift.at(j + 1) = tempcOL;
				}
			}
		}
	}
}
