/*7.1 LAB 1 (Part 1): Estimating PI
The Monte Carlo method is used in modeling a wide-range of physical systems at the forefront of scientific research today.Monte Carlo simulations are statistical models based on a series of random numbers. Let's consider the problem of estimating PI by utilizing the Monte Carlo method.

Suppose you have a circle inscribed in a square (as in the figure). The experiment simply consists of throwing darts on this figure completely at random (meaning that every point on the dartboard has an equal chance of being hit by the dart). How can we use this experiment to estimate Pi? The answer lies in discovering the relationship between the geometry of the figure and the statistical outcome of throwing the darts. Let's first look at the geometry of te figure.

Let's answer the radius of the circle is R, then the Area of the circle = Pi * R^2 and the Area of the square = 4 * R^2. Now if we divide the area of the circle by the area of the square we get Pi / 4.

But, how do we estimate Pi by simulation? In the simulation, you keep throwing darts at random onto the dartboard. All of the darts fall within the square, but not all of them fall within the circle. Here's the key. If you throw darts completely at random, this experiment estimates the ratio of the area of the circle to the area of the square, by counting the number of darts within each area. Our study of the geometry tells us this ratio is Pi/4. */

// pi = 4 * (# darts in circle) / (# darts in square)

// This program implements the Monte Carlo Method for estimating the value of PI.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Given the coordinates of a point (x, y), compute if the point is inside or on the circle.
// Centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.
bool isInside(double x, double y, double r) {
	if (pow(x, 2) + pow(y, 2) <= pow(r, 2)) {
		return true;
	}
	return false;
}

// Given s, the size of the side of a square that is centered at hte origin, chooses a random coordinates inside the square, and calls isInside function to test if the point is inside hte circle or not.
bool throwDart(int s) {
	int x, y;
	// Assign x and y to two random integers between -s/2 and s/2.
	x = rand() % (s + 1) - static_cast<double>(s) / 2;
	y = rand() % (s + 1) - static_cast<double>(s) / 2;

	// Call the inInside function and return its output.
	// You do not have to cast x & y to doubles, it is done automatically.
	if (isInside(x, y, static_cast<double>(s) / 2)) {
		return true;
	}
	return false;
}

int main() {
	srand(333);
	int side; // This is the side of the square and is also our resolution.
	int tries; // This is the number of tries.

	// Ask the user for the size (integer) of a side of the square.
	cout << "Input size of the sides of the square." << endl;

	// Get the users input using cin.
	cin >> side;

	// Ask the user for the number of tries using cout.
	cout << "Input number of tries." << endl;

	// Get the users input using cin.
	cin >> tries;

	int inCount = 0; // Counter to track number of throw that fall inside the circle.

	for (int i = 0; i < tries; ++i) {
		// Throw a dart using throwDart method and increment the counter depending on its output.
		if (throwDart(side)) {
			++inCount;
		}
	}

	// Compute and siplay the estimated value of PI. Make sure you are not using integer division.
	double pi = 4 * static_cast<double>(inCount) / tries;
	cout << pi << endl;

	return 0;
}
