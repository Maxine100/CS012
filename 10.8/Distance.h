#include <iostream>

using namespace std;

class Distance {
	private:
		unsigned feet;
		double inches;
	
	public:
		Distance();
		Distance(unsigned ft, double in);
		Distance(double in);
		unsigned getFeet() const;
		double getInches() const;
		double distanceInInches() const;
		double distanceInFeet() const;
		double distanceInMeters() const;
		const Distance operator+(const Distance &rhs) const;
		const Distance operator-(const Distance &rhs) const;
		friend ostream & operator<<(ostream &out, const Distance &rhs);
	
	private:
		void init();
};
