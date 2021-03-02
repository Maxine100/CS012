#include <iostream>
#include <sstream>

using namespace std;

#include "Distance.h"

Distance::Distance() {
	this->feet = 0;
	this->inches = 0.0;
}
Distance::Distance(unsigned ft, double in) {
	this->feet = ft;
	this->inches = in;
	init();
}
Distance::Distance(double in) {
	this->feet = 0;
	this->inches = in;
	init();
}
unsigned Distance::getFeet() const {
	return this->feet;
}
double Distance::getInches() const {
	return this->inches;
}
double Distance::distanceInInches() const {
	return this->feet * 12.0 + this->inches;
}
double Distance::distanceInFeet() const {
	return this->feet + this->inches / 12.0;
}
double Distance::distanceInMeters() const {
	return distanceInInches() * 0.0254;
}
const Distance Distance::operator+(const Distance &rhs) const {
	Distance sum;
	sum.feet = 0;
	sum.inches = distanceInInches() + rhs.distanceInInches();
	sum.init();
	return sum;
}

const Distance Distance::operator-(const Distance &rhs) const {
	Distance difference;
	difference.feet = 0;
	difference.inches = distanceInInches() - rhs.distanceInInches();
	difference.init();
	return difference;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
	out << rhs.feet << "' " << rhs.inches << "\"";
	return out;
}
void Distance::init() {
	if (feet < 0) {
		feet = feet * -1;
	}
	if (inches < 0) {
		inches = inches * -1;
	}
	while (inches >= 12.0) {
		inches = inches - 12.0;
		feet = feet + 1;
	}
}
