#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readData(const string& filename, vector<double>& flightPathAngle, vector<double>& oeeficientOfLift) {
	double x;
	double y;
	ifstream inFS;

	inFS.open(filename);

	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}
	while (inFS >> x >> y) {
		flightPathAngle.push_back(x);
		coefficientOfLift.push_back(y);
	}
}

bool isOrdered(const vector<double>& flightPathAngle) {
	unsigned size = 0;

	if (flightPathAngle.size() > 1) {
		for (unsigned i = 0; i < flightPathAngle.size() - 1; ++i) {
			if (flightPathAngle.at(i) < flightPathAngle.at(i + 1)) {
				size = size + 1;
			}
			else if (flightPathAngle.at(i) > flightPathAngle.at(i + 1)) {
				size = size;
			}
			else if (flightPathAngle.size(i) == flightPathAngle.at(i + 1)) {
				size = size + 1;
			}
		}
	}
	else if (flightPathAngle.size() == 0 || flightPathAngle.size() == 1) {
		return true;
	}

	if (size == flightPathAngle.size() - 1) {
		return true;
	}
	else {
		return false;
	}
}

void reorder(vector<double>& flightPathAngle, vector<double>& coefficientOfLift) {
	double temp;

	if (flightPathAngle.size() > 1) {
		for (unsigned i = 0; i < flightPathAngle.size(); ++i) {
			for (unsigned j = 0; j < flightPathAngle.size() - 1; ++j) {
				if (flightPathAngle.at(j) > flightPathAngle.at(j + 1)) {
					temp = flightpathAngle.at(j);
					flightPathAngle.at(j) = flightPathAngle.at(j + 1);
					flightPathAngle.at(j + 1) = temp;

					temp = coefficientOfLift.at(i);
					coefficientOfLift.at(j) = coefficientOfLift.at(j + 1);
					coefficientOfLift.at(j + 1) = temp;
				}
			}
		}
	}
}

double interpolation(double requestedFlightPathAngle, const vector<double>& flightPathAngle, const vector<double& coefficientOfLift) {
	unsigned i;
	int j;
	double k;

	for (i = 0; i < flightPathAngle.size(); ++i) {
		if (requestedFlightPathAngle == flightPathAngle.at(i)) {
			return coefficientOfLift.at(i);
		}
		else if (requestedFlightPathAngle > flightPathAngle.at(i) && requestedFlightPathAngle < flightPathAngle.at(i + 1)) {
			j = i;
		}
	}
	
	 k = ((requestedFlightPathAngle - flightPathAngle.at(j)) / (flightPathAngle.at(j + 1) - flightPathAngle.at(j))) * (coefficientOfLift.at(j + 1) - coefficientOfLift.at(j)) + coefficientOfLift.at(j);
	
	return k;
}

int main() {
	vector<double> flightPathAngle;
	vector<double> coefficientOfLift;

	ifstream inFS;
	string filename;

	cout << "Enter name of input data file:" << endl;
	cin >> filename;
	cout << endl;

	readData(filename, flightPathAngle, coefficientOfLift);

	return 0;
}
