#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Vector
{
private:
	double components[3];
public:
	Vector();
	Vector(double, double, double);
	friend const Vector operator+ (const Vector&, const Vector&);
	friend const Vector operator- (const Vector&, const Vector&);
	friend const Vector operator- (const Vector&); // sign flip
	friend const Vector operator* (const Vector&, const Vector&); // cross multiply
	Vector& operator= (const Vector&);
	friend ostream& operator <<(ostream&, const Vector&);
	friend istream& operator >>(istream&, Vector&);
	friend bool operator>(const Vector&, const Vector&);
	friend bool operator<(const Vector&, const Vector&);
	friend bool operator==(const Vector&, const Vector&);
	friend bool operator>=(const Vector&, const Vector&);
	friend bool operator<=(const Vector&, const Vector&);
	double& operator[](int);
	friend double getMagnitude(const Vector&); // returns the magnitude
};